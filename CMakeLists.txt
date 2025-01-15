cmake_minimum_required(VERSION 3.10)
project(NeuralNetwork)

#Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect source files
set(SOURCES
    src/main.cpp
    src/Neural_Network.cpp
    src/Node.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})