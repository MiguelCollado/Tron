include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Tron"
    architecture "x86_64"
    startproject "Tron-Editor"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    solution_items {
        ".editorconfig"
    }

    flags {
        "MultiProcessorCompile"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Tron/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Tron/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Tron/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Tron/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Tron/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Tron/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Tron/vendor/GLFW"
	include "Tron/vendor/Glad"
	include "Tron/vendor/imgui"

group ""

include "Tron"
include "Sandbox"
include "Tron-Editor"