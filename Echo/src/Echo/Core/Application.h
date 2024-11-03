#pragma once

namespace Echo {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        bool m_Running;
    };

    extern Application* CreateApplication();
}
