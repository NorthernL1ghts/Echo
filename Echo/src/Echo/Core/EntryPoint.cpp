#include "Application.h"
#include "Log.h"

#ifdef ECHO_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
    Echo::Log::Init();
    ECHO_CORE_WARN("Initialized Log!");
    int a = 5;
    ECHO_INFO("Hello! Var={0}", a);

    // Create and populate the command line arguments
    Echo::ApplicationCommandLineArgs args;
    args.Count = argc;
    args.Args = argv;

    // Create the application instance and pass the command line arguments
    Echo::Application* app = Echo::CreateApplication(args);
    app->Run();
    delete app;
    return 0;
}

#endif // ECHO_PLATFORM_WINDOWS