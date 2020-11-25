project(tests)

# Based on the CLion tutorial:
# https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html#add-google-tests
# https://www.jetbrains.com/help/clion/unit-testing-tutorial.html#adding-framework

# lib directory includes the GoogleTest sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'tests_run' is the target name
add_executable(tests_run vec3_test.cpp ray_test.cpp)
target_link_libraries(tests_run gtest gtest_main CommonSR)


