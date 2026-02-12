cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(calc)

# Create the library
add_library(maths adder.cpp)

# Handle static/dynamic definitions
if(NOT BUILD_SHARED_LIBS)
    add_definitions(-Dmaths_STATIC)
endif()

# Create executable
add_executable(calc calc.cpp)

# Link library to executable
target_link_libraries(calc maths)
