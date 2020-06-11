workspace "DoublyLinkedList"
	architecture "x64"
	startproject "DoublyLinkedList"
	systemversion "latest"
	cppdialect "C++17"

	configurations
	{
		"Debug"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "DoublyLinkedList"
	location "DoublyLinkedList"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/" .. outputdir .. "/%{prj.name}")
	
	defines
	{
		"GLEW_STATIC"
	}

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/include"
	}
	
	