workspace "Space Shooter Clone"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "SpaceShooterClone"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/")
    objdir ("obj/" .. outputdir .. "/")

    files {
        "src/**.hpp",
        "src/**.cpp",
        "src/Game/**.hpp",
        "src/Game/**.cpp",
        "src/Engine/**.hpp",
        "src/Engine/**.cpp"
    }

    includedirs {
        "thirdparty/SFML/include/",
        "src/"
    }

    libdirs {
        "thirdparty/SFML/lib"
    }

    defines {
        "SFML_STATIC"
    }

    links {
        "opengl32.lib",
        "winmm.lib",
        "gdi32.lib"
    }


filter "configurations:Debug"
    links {
        "sfml-system-s-d.lib",
        "sfml-window-s-d.lib",
        "sfml-graphics-s-d.lib",
        "sfml-audio-s-d.lib"
    }
    symbols "On"

filter "configurations:Release"
    links {
        "sfml-system-s.lib",
        "sfml-window-s.lib",
        "sfml-graphics-s.lib",
        "sfml-audio-s.lib"
    }
    optimize "On"