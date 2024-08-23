# CMakeLists.txt in source folder

# Set the project name for the source files
project(MyProjectSource LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the source directory variables
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Collect all the source files
file(GLOB_RECURSE SOURCE_FILES
    ${SRC_DIR}/*.cc
    ${SRC_DIR}/*.cpp
)

# Add a library target for the source files (optional, for modularity)
add_library(SourceLib STATIC ${SOURCE_FILES})

# Include directories for headers
target_include_directories(SourceLib PUBLIC ${INC_DIR})
