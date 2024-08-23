# CMakeLists.txt in TEST folder

# Set the project name for the test files
project(UnitTests LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all the test source files
set(TEST_SOURCES
    #${CMAKE_CURRENT_SOURCE_DIR}/CuteTest.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/test.cc
    # Add more test files as needed
)

# Add the UNITTEST executable
add_executable(UNITTEST ${TEST_SOURCES})

# Include directories from the main project
target_include_directories(UNITTEST PRIVATE ${PROJECT_ROOT_DIR}/CUTE)
target_include_directories(UNITTEST PRIVATE ${PROJECT_ROOT_DIR}/CUTE/cute)

# Link Google Test libraries
target_link_libraries(UNITTEST gtest gtest_main)

# Enable testing
enable_testing()

# Register the tests with CTest
add_test(NAME UnitTest COMMAND UNITTEST)
