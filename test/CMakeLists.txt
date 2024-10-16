# Check if test framework is installed
find_package(GTest REQUIRED)

# Create test executable
add_executable(LatticeFlowTest)

# Link test executable against test framework
target_link_libraries(LatticeFlowTest PRIVATE
    GTest::GTest
    GTest::Main
)

# Set compile flags for test executable
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(LatticeFlowTest PRIVATE
        -g
        -O0
        -Wall
        -Wextra
        -Werror
        -Wpedantic
    )
endif()

# Discover tests from test executable
gtest_discover_tests(LatticeFlowTest)

# Add test directories
add_subdirectory(d2q9)
