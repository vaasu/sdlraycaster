cmake_minimum_required(VERSION 3.13.3)
project(sdlraycaster)
set(CMAKE_MODULE_PATH "/usr/lib/cmake/glm/;/usr/share/SFML/cmake/Modules/;${CMAKE_MODULE_PATH}")
# set(CMAKE_MODULE_PATH "/usr/lib/cmake/glm/;${CMAKE_MODULE_PATH}")
find_package( SFML 2 REQUIRED graphics window system)
include_directories(src)

set(CMAKE_CXX_FLAGS "-fpermissive ")

option(USE_GLM_MATH "Use glm math library" ON)

if(USE_GLM_MATH)
    add_definitions(-DUSE_GLM_MATH)
    add_subdirectory(external/glm/)
    find_package(glm REQUIRED)
endif(USE_GLM_MATH)

add_executable(raycaster src/main.cpp)
target_sources(raycaster PUBLIC src/window.cpp src/map.h src/framebuffer.cpp src/sdlraycaster.cpp src/model/model.cpp src/model/scene_object.cpp src/world.cpp src/rasterizer/rasterizer.cpp)
target_link_libraries(raycaster PUBLIC sfml-graphics sfml-window sfml-system)

add_subdirectory(external/googletest)
add_subdirectory(test)
