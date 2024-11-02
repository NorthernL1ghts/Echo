#pragma once

namespace Echo {

    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();

    private:
        bool m_Running; // Member variable to keep track of running state
    };

    extern Application* CreateApplication();
}
