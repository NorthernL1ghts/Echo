workspace "Echo"
    configurations { "Debug", "Dist", "Release" }
    architecture "x64"  -- Ensure this is explicitly set

    outputdir = "%{cfg.buildcfg}/%{cfg.architecture}"

    -- Set output and intermediate directories
    targetdir("$(SolutionDir)bin/" .. outputdir .. "/%{prj.name}")
    objdir("$(SolutionDir)bin-int/" .. outputdir .. "/%{prj.name}")

project "Echo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    defines { "ECHO_PLATFORM_WINDOWS" }
    files { "Echo/src/Echo/Core/**.h", "Echo/src/Echo/Core/**.cpp" }

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
