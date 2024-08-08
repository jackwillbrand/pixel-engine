#!/bin/bash

# Define the project directory and build directory
PROJECT_DIR=/code/pixel-engine
BUILD_DIR=$PROJECT_DIR/build

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# Change to the build directory
cd "$BUILD_DIR"

# Run cmake and make commands
cmake ..
if [ $? -ne 0 ]; then
    echo "CMake failed"
    exit 1
fi

make
if [ $? -ne 0 ]; then
    echo "Make failed"
    exit 1
fi

echo "Build successful"
