#include "Application.h"
#include "Log.h"
#include <iostream>

namespace Echo {

    Application::Application()
        : m_Running(true)
    {
    }

    Application::~Application() {
    }

    void Application::Run() {
        while (m_Running) {
            ECHO_CORE_TRACE("Application is running...");

            char input;
            std::cout << "Press 'q' to quit: ";
            std::cin >> input;
            if (input == 'q') {
                m_Running = false;
                ECHO_CORE_INFO("Application is stopping...");
            }
        }
    }

    Application* CreateApplication() {
        return new Application(); // Adjust if you have a derived class of Application
    }

} // namespace Echo
