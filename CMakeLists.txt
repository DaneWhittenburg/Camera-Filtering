# Minimum version of cmake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(active_streaming CXX)

# C++ Standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# List required packages
find_package(OpenCV REQUIRED)

# list executable
add_executable(active_streaming 
                src/main.cpp
                src/camera_functions/camera_functions.cpp
                src/filtering/rgb_filter.cpp)

# link libraries
target_link_libraries(active_streaming ${OpenCV_LIBS})

# include directories
target_include_directories(active_streaming PRIVATE ${OpenCV_INCLUDE_DIRS})