project "PrimeEngine-Game"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp", "Source/main.cpp" }

   includedirs
   {
      "Source",

	  -- Include Core
	  "../PrimeEngine-Core/Source",

      -- SDL from core
      "../PrimeEngine-Core/Libraries/SDL2/include",
      "../PrimeEngine-Core/Libraries/SDL2_image/include",
      "../PrimeEngine-Core/Libraries/SDL2_ttf/include"
   }

   links
   {
      "PrimeEngine-Core",
      "SDL2",
      "SDL2_image",
      "SDL2_ttf"
   }

    libdirs
    {
        "../PrimeEngine-Core/Libraries/SDL2/lib",
        "../PrimeEngine-Core/Libraries/SDL2_image/lib",
        "../PrimeEngine-Core/Libraries/SDL2_ttf/lib",

        "../Binaries/" .. OutputDir .. "/PrimeEngine-Core"
    }

    postbuildcommands
    {
        '{COPY} "../PrimeEngine-Core/Libraries/SDL2/lib/SDL2.dll" "%{cfg.targetdir}"',
        '{COPY} "../PrimeEngine-Core/Libraries/SDL2_image/lib/SDL2_image.dll" "%{cfg.targetdir}"',
        '{COPY} "../PrimeEngine-Core/Libraries/SDL2_ttf/lib/SDL2_ttf.dll" "%{cfg.targetdir}"'
    }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

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
