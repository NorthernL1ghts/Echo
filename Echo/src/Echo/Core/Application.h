#pragma once

namespace Echo {

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        bool m_Running; // Application running state
    };

    Application* CreateApplication(); // Function prototype

} // namespace Echo
