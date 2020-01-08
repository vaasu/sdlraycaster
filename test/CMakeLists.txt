enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(unit_tests src/test_world.cpp)
target_link_libraries(unit_tests gtest_main)
