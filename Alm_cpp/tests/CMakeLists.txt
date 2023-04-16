cmake_minimum_required(VERSION 3.16)

project(Alm_tests VERSION 1.0)
set(CMAKE_CXX_FLAGS "-I/usr/include/  -O2")
set(CMAKE_C_FLAGS "-I/usr/include/  -O2")
set(CMAKE_CXX_STANDARD 17)

# Add the path to the Boost library directory
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS iostreams program_options filesystem)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Find the Google Test library
find_package(GTest REQUIRED)
find_package(GSL REQUIRED)

#Look for eigen and explicitly specify to use it. EIGEN3_INCLUDE_DIR Must be specified in the bashrc
include_directories( "$ENV{EIGEN3_INCLUDE_DIR}" )
# Add the gtest include directory to the project
include_directories(${GTEST_INCLUDE_DIRS} ../)
#Bring the core program sources into the project
set(SOURCES  #_COMMON
    ../activity.cpp
    ../linspace.cpp
    ../string_handler.cpp
    ../GaussLegendre1D.hpp
    ../GaussLegendre2D.hpp
    ../make_grids.cpp
    ../do_grids.cpp
    ../gzip_compress.cpp
    ../bilinear_interpol.cpp
    ../Alm_interpol.cpp
    )

# Add the executable target and include the source files and header files needed
add_executable(test_all unit_tests.cpp ${SOURCES})
# Add the Google Test framework library to the project by linking it to the executable
target_link_libraries(test_all ${Boost_LIBRARIES} ${GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the test binary
set_target_properties(test_all PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/test_bin")
# Add a command to run the tests using CTest
include(GoogleTest)
gtest_discover_tests(test_all)
