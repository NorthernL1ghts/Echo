workspace "Echo"
    configurations { "Debug", "Dist", "Release" }
    architecture "x64"

    outputdir = "%{cfg.buildcfg}/%{cfg.architecture}"

    -- Set output and intermediate directories
    targetdir("$(SolutionDir)bin/" .. outputdir .. "/%{prj.name}")
    objdir("$(SolutionDir)bin-int/" .. outputdir .. "/%{prj.name}")

project "Echo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    defines { "ECHO_PLATFORM_WINDOWS" }

    -- Include path for spdlog
    includedirs { 
        "C:/Dev/Echo/Echo/vendor/spdlog/include",  -- Use the specified path
        "Echo/src"  -- Add this line to include the src directory
    }

    -- Include all files while maintaining directory structure
    files { 
        "Echo/src/**.h", 
        "Echo/src/**.cpp" 
    }

    -- Enable UTF-8 compilation for Visual Studio
    filter "action:vs*"
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        runtime "Debug"

    filter "configurations:Dist"
        defines { "DIST" }
        symbols "On"
        runtime "Release"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
        runtime "Release"

    filter {}
