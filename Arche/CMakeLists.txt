cmake_minimum_required(VERSION 3.10)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project configuration
project(Arche VERSION 1.0.0)

# Add subdirectory for the library
add_subdirectory(lib)

# Add subdirectory for spdlog
add_subdirectory(spdlog)

# Add subdirectory for the application
add_subdirectory(app)
