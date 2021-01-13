project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Tron/vendor/spdlog/include",
		"%{wks.location}/Tron/src",
		"%{wks.location}/Tron/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Tron"
	}

	filter "system:windows"
		systemversion "latest"

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