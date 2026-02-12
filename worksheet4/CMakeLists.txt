cmake_minimum_required(VERSION 3.10)
project(Worksheet4 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectory for the library
add_subdirectory(maths)

# Create the Hello World executable
add_executable(hello hello.cpp)

# Create the Static Calculator
add_executable(calc_static calc.cpp)
target_link_libraries(calc_static PUBLIC maths_static)

# Create the Dynamic Calculator
add_executable(calc_dynamic calc.cpp)
target_link_libraries(calc_dynamic PUBLIC maths_shared)

# Installation rules for the executables to match the README instructions
install(TARGETS calc_static
    RUNTIME DESTINATION bin
    COMPONENT Static
)

install(TARGETS calc_dynamic
    RUNTIME DESTINATION bin
    COMPONENT Dynamic
)

install(TARGETS hello
    RUNTIME DESTINATION bin
    # No component specified, or could be both? 
    # Usually 'Unspecified' component.
)
