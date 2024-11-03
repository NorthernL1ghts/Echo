#include "Application.h"
#include "Log.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <conio.h>

namespace Echo {

    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpecification& specification)
        : m_Specification(specification)
    {
        s_Instance = this;

        // Set working directory here
        if (!m_Specification.WorkingDirectory.empty())
            std::filesystem::current_path(m_Specification.WorkingDirectory);

        // Example usage of FileSystem
        TestFileSystem(); // Call the test method
    }

    Application::~Application() {}

    void Application::Run()
    {
        while (m_Running)
        {
            ExecuteMainThreadQueue();
            TerminateOnHotKey('q');
        }
    }

    void Application::TerminateOnHotKey(char keycode)
    {
        if (_kbhit())
        {
            char input = _getch();
            if (input == keycode || input == toupper(keycode))
            {
                Close();
            }
        }
    }

    void Application::Close()
    {
        ECHO_INFO("Application is stopping...");
        m_Running = false;
    }

    void Application::SubmitToMainThread(const std::function<void()>& function)
    {
        std::scoped_lock<std::mutex> lock(m_MainThreadQueueMutex);
        m_MainThreadQueue.emplace_back(function);
    }

    void Application::ExecuteMainThreadQueue()
    {
        std::scoped_lock<std::mutex> lock(m_MainThreadQueueMutex);

        for (auto& func : m_MainThreadQueue)
            func();

        m_MainThreadQueue.clear();
    }

    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        return new Application(ApplicationSpecification()); // Adjust to pass args if needed
    }
}
