# StingRay
A raytracing engine based on Peter Shirley's book: Ray Tracing in One Weekend. 

## Building
The main binary and tests are generated by CMake and the generated Makefile:
`CMake .`
`make`

This will build the main and test binaries found in the bin folder, as well as the googletest library found in lib.

## Running
The renderer outputs raw image data in ppm format. Therefore to save the file you need to pipe the program into a new ppm file. For example from the root directory of the project:
`./bin/stingRay > ~/Desktop/demo.ppm`

The test binary is also generated in the bin folder. To run the tests:
`./bin/tests_run`



