#include "Application.h"
#include <iostream>

namespace Echo {

    Application::Application()
        : m_Running(true) // Initialize running state to true
    {
    }

    Application::~Application() {
        // Cleanup code can be added here if necessary
    }

    void Application::Run() {
        while (m_Running) {
            std::cout << "Application is running..." << std::endl;

            char input;
            std::cout << "Press 'q' to quit: ";
            std::cin >> input;
            if (input == 'q') {
                m_Running = false; // Stop the application
            }
        }
    }

    // Create and return a new Application instance
    Application* CreateApplication() {
        return new Application();
    }

} // namespace Echo
