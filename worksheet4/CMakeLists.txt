cmake_minimum_required(VERSION 3.23)
project(Worksheet4)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output all binaries to the same directory (bin) to avoid DLL issues on Windows
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the maths library subdirectory
add_subdirectory(maths)

# Executables
add_executable(calc_static calc.cpp)
target_link_libraries(calc_static PRIVATE maths_static)

add_executable(calc_dynamic calc.cpp)
target_link_libraries(calc_dynamic PRIVATE maths_shared)

add_executable(hello hello.cpp)

# Installation - Static Component
install(TARGETS calc_static hello
    RUNTIME DESTINATION bin
    COMPONENT Static)

# Installation - Dynamic Component
install(TARGETS calc_dynamic
    RUNTIME DESTINATION bin
    COMPONENT Dynamic)
