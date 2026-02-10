add_library(maths_static STATIC adder.cpp adder.h)
target_include_directories(maths_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(maths_static PUBLIC maths_STATIC)

add_library(maths_shared SHARED adder.cpp adder.h)
target_include_directories(maths_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(maths_shared PRIVATE maths_EXPORTS)

# Installation - Static Component
install(TARGETS maths_static
    ARCHIVE DESTINATION lib COMPONENT Static)

# Installation - Dynamic Component
install(TARGETS maths_shared
    RUNTIME DESTINATION bin COMPONENT Dynamic
    LIBRARY DESTINATION lib COMPONENT Dynamic
    ARCHIVE DESTINATION lib COMPONENT Dynamic)

# Common headers
install(FILES adder.h
    DESTINATION include
    COMPONENT Static)
install(FILES adder.h
    DESTINATION include
    COMPONENT Dynamic)
