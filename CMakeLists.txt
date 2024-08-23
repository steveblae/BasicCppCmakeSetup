cmake_minimum_required(VERSION 3.10)

# Set the project name and languages
project(MyProject LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the root directory variables
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(BUILD_DIR ${PROJECT_ROOT_DIR}/build)

# Set the output directories for different types of targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)

# Include directories for headers
include_directories(${PROJECT_ROOT_DIR}/CUTE)
include_directories(${PROJECT_ROOT_DIR}/CUTE/cute)

# Add the executable target for the main project
add_executable(MyProject ${PROJECT_ROOT_DIR}/main.cc)

# Add the TEST subdirectory
add_subdirectory(TEST)

# Create custom targets to build either the main project or the tests
add_custom_target(run_myproject
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/MyProject
    DEPENDS MyProject
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Running MyProject executable..."
)

add_custom_target(run_tests
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/UNITTEST
    DEPENDS UNITTEST
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Running UNITTEST executable..."
)




# cmake_minimum_required(VERSION 3.10)

# # Set the project name
# project(MyProject)

# # Specify the C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Define the root directory variables
# set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})
# set(BUILD_DIR ${PROJECT_ROOT_DIR}/build)

# # Set the output directories for different types of targets
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)

# # Include directories
# include_directories(CUTE)
# include_directories(CUTE/cute)

# # Add the executable
# add_executable(MyProject main.cc)