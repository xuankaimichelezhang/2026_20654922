add_library(maths adder.cpp adder.h)

# Allow other targets to find our header
target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Define the static macro for everyone using this library
target_compile_definitions(maths PUBLIC maths_STATIC)
