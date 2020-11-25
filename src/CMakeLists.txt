# Create a header only library
# https://stackoverflow.com/questions/60604249/how-to-make-a-header-only-library-with-cmake

# Do not add any specific files to the add_library function. Files are added under the common directory
add_library(CommonSR INTERFACE)
target_include_directories(CommonSR INTERFACE common/)

add_executable(stingRay main.cpp)
target_link_libraries(stingRay CommonSR)