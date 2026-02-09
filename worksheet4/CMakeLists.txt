cmake_minimum_required(VERSION 3.23)

project(Worksheet4)

# Add the maths library subdirectory
add_subdirectory(maths)

# Create the calc executable
add_executable(calc calc.cpp)

# Link the maths library
target_link_libraries(calc PRIVATE maths)
