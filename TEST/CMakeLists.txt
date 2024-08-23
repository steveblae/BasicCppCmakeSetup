# CMakeLists.txt in TEST folder

# Set the project name for the test files
project(UnitTests LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
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



# # CMakeLists.txt in TEST folder

# # Specify the minimum required version of CMake
# cmake_minimum_required(VERSION 3.10)

# # Set the project name for the test files
# project(UnitTests LANGUAGES CXX)

# # Specify the C++ standard (inherit from parent or define explicitly)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Collect all the test source files
# set(TEST_SOURCES
#     ${CMAKE_CURRENT_SOURCE_DIR}/test1.cc
#     ${CMAKE_CURRENT_SOURCE_DIR}/test2.cc
#     # Add more test files as needed
# )

# # Add the UNITTEST executable
# add_executable(UNITTEST ${TEST_SOURCES})

# # Include directories from the main project
# target_include_directories(UNITTEST PRIVATE ${PROJECT_ROOT_DIR}/CUTE)
# target_include_directories(UNITTEST PRIVATE ${PROJECT_ROOT_DIR}/CUTE/cute)