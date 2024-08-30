# Basic Cmake C++ Project

## Before getting started


You'll need at least **one compiler**, along with **CMake** and **Make**, installed on your machine. If you're using macOS with Xcode installed, the ARM version of Clang is already included. To install the GCC compiler, you can use Homebrew by running: brew install gcc. On Windows, the Chocolatey package manager can be used for installation. 

The simplest way to work with this repository is by using **Visual Studio Code** with the **CMake extension**.

## How to build and run on Command Line

### build project

cmake --build build --target MyProject

### run main project

cmake --build build --target run_myproject


### build unitest

cmake --build build --target UNITTEST

### run unitest

cmake --build build --target run_tests
