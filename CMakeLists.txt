cmake_minimum_required(VERSION 3.13.3)
project(sdlraycaster)
find_package(SDL2 REQUIRED)
include_directories(sdlraycaster ${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-fpermissive ")

add_executable(raycaster src/Main.cpp)
target_sources(raycaster PUBLIC src/Window.cpp src/Map.h src/Framebuffer.cpp src/Utils.cpp)
target_link_libraries(raycaster PUBLIC SDL2)