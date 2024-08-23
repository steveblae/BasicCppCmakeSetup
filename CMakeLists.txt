cmake_minimum_required(VERSION 3.10)

# Set the project name and languages
project(MyProject LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define BUILD directory
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(BUILD_DIR ${PROJECT_ROOT_DIR}/build)

# Include directories for headers
include_directories(${PROJECT_ROOT_DIR}/CUTE)
include_directories(${PROJECT_ROOT_DIR}/CUTE/cute)


# Add the executable target for the main project
add_executable(MyProject ${PROJECT_ROOT_DIR}/main.cc)

# Link the executable with the library
target_link_libraries(MyProject PRIVATE SourceLib)

# Add the Google Test subdirectory
add_subdirectory(googletest)

# Add the TEST subdirectory
add_subdirectory(TEST)

# Add the subdirectory for the source code
add_subdirectory(source)

# Create custom targets to build either the main project or the tests
add_custom_target(RunMyProject
    COMMAND MyProject
    DEPENDS MyProject
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Running MyProject executable..."
)

add_custom_target(RunUnitTest
    COMMAND UNITTEST
    DEPENDS UNITTEST
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Running UNITTEST executable..."
)