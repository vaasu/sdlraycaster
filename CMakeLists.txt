cmake_minimum_required(VERSION 3.13.3)
project(sdlraycaster)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/;${CMAKE_MODULE_PATH}")
find_package( SFML 2 REQUIRED graphics window system)
include_directories(sdlraycaster)

set(CMAKE_CXX_FLAGS "-fpermissive ")

add_executable(raycaster src/main.cpp)
target_sources(raycaster PUBLIC src/window.cpp src/map.h src/framebuffer.cpp src/utils.cpp)
target_link_libraries(raycaster PUBLIC sfml-graphics sfml-window sfml-system)