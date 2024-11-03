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

    void Application::TestFileSystem()
    {
        const std::string baseDir = "C:/Dev/test_directory"; // Use forward slashes for cross-platform compatibility
        const std::string testFile = baseDir + "/test_file.txt";

        // Create directory
        if (m_FileSystem.CreateDirectory(baseDir)) {
            ECHO_INFO("Directory created: " + baseDir);
        }
        else {
            ECHO_INFO("Failed to create directory: " + baseDir);
        }

        // Write to file
        if (m_FileSystem.WriteFile(testFile, "Hello, Echo!")) {
            ECHO_INFO("File written: " + testFile);
        }
        else {
            ECHO_INFO("Failed to write file: " + testFile);
        }

        // Read from file
        std::string content = m_FileSystem.ReadFile(testFile);
        ECHO_INFO("Content read from file: " + content);

        // List files in the directory
        std::vector<std::string> files = m_FileSystem.ListFiles("C:/Dev");
        ECHO_INFO("Files in directory C:/Dev:");
        for (const auto& file : files) {
            ECHO_INFO(" - " + file);
        }

        // Delete file
        if (m_FileSystem.DeleteFile(testFile)) {
            ECHO_INFO("File deleted: " + testFile);
        }
        else {
            ECHO_INFO("Failed to delete file: " + testFile);
        }

        // Delete directory
        if (std::filesystem::remove_all(baseDir)) { // Use remove_all to delete directory and contents
            ECHO_INFO("Directory deleted: " + baseDir);
        }
        else {
            ECHO_INFO("Failed to delete directory: " + baseDir);
        }
    }


    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        return new Application(ApplicationSpecification()); // Adjust to pass args if needed
    }
}
