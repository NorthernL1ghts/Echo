#include "Application.h"
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
            std::cout << "Application is running..." << std::endl;

            char input;
            std::cout << "Press 'q' to quit: ";
            std::cin >> input;
            if (input == 'q') {
                m_Running = false;
            }
        }
    }

    Application* CreateApplication() {
        return new Application();
    }

} // namespace Echo
