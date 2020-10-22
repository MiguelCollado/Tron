workspace "Tron"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tron"
    location "Tron"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "TN_PLATFORM_WINDOWS",
            "TN_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "TN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TN_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Tron/src",
        "Tron/vendor/spdlog/include"
    }

    links {
        "Tron"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "TN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TN_DIST"
        optimize "On"