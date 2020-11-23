project(tests)

# Based on the CLion tutorial:
# https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html#add-google-tests

# lib directory includes the GoogleTest sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
# add_executable(tests_run test1.cpp tests2.cpp)
# target_link_libraries(Google_Tests_run gtest gtest_main)
