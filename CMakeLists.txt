# Set minimum CMake version
cmake_minimum_required(VERSION 3.30)

# Set project information
project(
    LatticeFlow
    VERSION 0.1.0
    DESCRIPTION "C++ library for Computational Fluid Dynamics based on the Lattice Boltzmann Method"
    LANGUAGES CXX
)

# Set strict ISO C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Process build type
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ENABLE_TESTING ON)
endif()

# Enable export of compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add test root directory
if (ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif()

# Add documentation root directory
add_subdirectory(doc)
