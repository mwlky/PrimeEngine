cmake_minimum_required(VERSION 3.26)
project(PrimeEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(PrimeEngine main.cpp
        Source/Game/GameManager.cpp
        Source/Game/GameManager.h
        Source/PrimeEngine/PrimeEngine.cpp
        Source/PrimeEngine/PrimeEngine.h
        Source/PrimeEngine/Window.h
        Source/PrimeEngine/Managers/SpriteManager.cpp
        Source/PrimeEngine/Managers/SpriteManager.h
        Source/PrimeEngine/Components/Sprite.h
        Source/PrimeEngine/Window.cpp
        Source/PrimeEngine/Math/Vector2.cpp
        Source/PrimeEngine/Math/Vector2.h
        Source/PrimeEngine/Components/ECS.h
        Source/PrimeEngine/Components/Components.h
        Source/PrimeEngine/Components/Transform.h
)

target_link_libraries(PrimeEngine
        ${SDL2_LIBRARIES}
        /usr/lib/libSDL2_image.so  # Provide the full path to the SDL2_image library
)
