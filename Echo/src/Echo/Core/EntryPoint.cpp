#include "Application.h"  // Include the Application header to access CreateApplication()

#ifdef ECHO_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
    auto app = Echo::CreateApplication(); // Create the application instance
    app->Run();                           // Run the application
    delete app;                           // Clean up the application instance
    return 0;                             // Return exit code
}

#endif // ECHO_PLATFORM_WINDOWS
