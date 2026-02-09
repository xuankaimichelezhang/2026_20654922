cmake_minimum_required(VERSION 3.23)

project(Worksheet4)

# Set common flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the maths library subdirectory
add_subdirectory(maths)

# Calculator Executable
add_executable(calc_cmake calc.cpp)
target_link_libraries(calc_cmake PRIVATE maths)

# Hello World Executable
add_executable(hello_cmake hello.cpp)
