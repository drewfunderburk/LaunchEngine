workspace "Launch"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Launch"
	location "Launch"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glfw-3.3.4.bin.WIN64/include",
		"%{prj.name}/vendor/glew-2.1.0/include"
	}

	libdirs
	{
		"%{prj.name}/vendor/glfw-3.3.4.bin.WIN64/lib-vc2019",
		"%{prj.name}/vendor/glew-2.1.0/lib/Release/x64"
	}

	links
	{
		"glfw3",
		"glew32s",
		"opengl32"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS",
			"LN_BUILD_DLL",
			"GLEW_STATIC"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} ../Launch/src/Launch/Graphics/Shaders/OpenGL_Basic.shader ../Sandbox/src/Shaders/OpenGL_Basic.shader")
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LN_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Launch/vendor/spdlog/include",
		"Launch/src"
	}

	links
	{
		"Launch"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LN_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LN_DIST"
		optimize "On"