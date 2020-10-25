workspace "Tron"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Tron/vendor/GLFW/include"
IncludeDir["Glad"] = "Tron/vendor/Glad/include"
IncludeDir["ImGui"] = "Tron/vendor/imgui"
IncludeDir["glm"] = "Tron/vendor/glm"

group "Dependencias"
    include "Tron/vendor/GLFW"
    include "Tron/vendor/Glad"
    include "Tron/vendor/imgui"

group ""


project "Tron"
    location "Tron"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "tnpch.h"
    pchsource "Tron/src/tnpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "TN_PLATFORM_WINDOWS",
            "TN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "TN_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TN_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "TN_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Tron/src",
        "Tron/vendor",
        "Tron/vendor/spdlog/include",
        "%{IncludeDir.glm}"
    }

    links {
        "Tron"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "TN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TN_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TN_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "TN_DIST"
        runtime "Release"
        optimize "on"