workspace "Kepler"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kepler"
	location "Kepler"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WIN",
			"KP_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kepler/vendor/spdlog/include",
		"Kepler/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KP_PLATFORM_WIN",
		}

	links
	{
		"Kepler"
	}

	filter "configurations:Debug"
		defines "KP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KP_DIST"
		optimize "On"