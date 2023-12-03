project "PrimeEngine-Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",

      -- Include SDL
      "Libraries/SDL2/include",
      "Libraries/SDL2_image/include",
      "Libraries/SDL2_ttf/include"
   }

   links
   {
      "SDL2",
      "SDL2_image",
      "SDL2_ttf"
   }

   libdirs
   {
      "Libraries/SDL2/lib",
      "Libraries/SDL2_image/lib",
      "Libraries/SDL2_ttf/lib"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
