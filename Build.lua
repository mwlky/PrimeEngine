-- premake5.lua
workspace "PrimeEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "PrimeEngine-Game"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "PrimeEngine-Core/Build-Core.lua"
group ""

include "PrimeEngine-Game/Build-App.lua"
