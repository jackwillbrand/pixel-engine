cmake_minimum_required(VERSION 3.10)

# Project Name
project(MySFMLProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add executable
add_executable(sfml_test main.cpp)

# Link SFML libraries
target_link_libraries(sfml_test sfml-graphics sfml-window sfml-system)
