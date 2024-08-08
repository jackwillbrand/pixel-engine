cmake_minimum_required(VERSION 3.10)
project(pixel-game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SDL2_TTF_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2_ttf.so")
set(SDL2_MIXER_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2_mixer.so")
set(SDL2_IMAGE_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")

add_executable(pixel-engine main.cpp)

target_link_libraries(pixel-engine ${SDL2_LIBRARIES})
target_link_libraries(pixel-engine ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(pixel-engine ${SDL2_TTF_LIBRARIES})
target_link_libraries(pixel-engine ${SDL2_MIXER_LIBRARIES})
