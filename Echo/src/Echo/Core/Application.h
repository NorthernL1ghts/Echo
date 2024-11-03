#pragma once

#include "Assert.h"

#include <string>
#include <functional>
#include <vector>
#include <mutex>
#include <filesystem>

namespace Echo {

    struct ApplicationCommandLineArgs
    {
        int Count = 0;
        char** Args = nullptr;

        const char* operator[](int index) const
        {
            ECHO_ASSERT(index >= 0 && index < Count, "Index out of bounds"); // Use assertion for index safety
            return Args[index];
        }
    };

    struct ApplicationSpecification
    {
        std::string Name = "Echo Application";
        std::string WorkingDirectory;
        ApplicationCommandLineArgs CommandLineArgs;
    };

    class Application {
    public:
        Application(const ApplicationSpecification& specification);
        virtual ~Application();

        void Run();
        void Close();
        static Application& Get() {
            ECHO_CORE_ASSERT(s_Instance, "Application instance is null!"); // Ensure instance is valid
            return *s_Instance;
        }

        const ApplicationSpecification& GetSpecification() const {
            return m_Specification;
        }

        void SubmitToMainThread(const std::function<void()>& function);
        void TerminateOnHotKey(char keycode);

    private:
        void ExecuteMainThreadQueue();

    private:
        ApplicationSpecification m_Specification;
        bool m_Running = true;
        std::vector<std::function<void()>> m_MainThreadQueue;
        std::mutex m_MainThreadQueueMutex;

    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication(ApplicationCommandLineArgs args);
}
