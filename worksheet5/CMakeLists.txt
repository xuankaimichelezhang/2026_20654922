cmake_minimum_required(VERSION 3.23)
project(Worksheet5)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files are in the same directory
add_library(maths STATIC adder.cpp adder.h)
target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(maths PUBLIC maths_STATIC)

add_executable(calc calc.cpp)
target_link_libraries(calc PRIVATE maths)

# Installation rules
install(TARGETS calc maths
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)

install(FILES adder.h
    DESTINATION include)

# CPack configuration
if(WIN32)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_PACKAGE_NAME "CalculatorInstaller")
    set(CPACK_PACKAGE_VENDOR "Xuankai Zhang")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple calculator with maths library")
    set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
else()
    set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)
