cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CylinderExample)

find_package(VTK COMPONENTS
    CommonColor
    CommonCore
    FiltersSources
    InteractionStyle
    RenderingContextOpenGL2
    RenderingCore
    RenderingFreeType
    RenderingGL2PSOpenGL2
    RenderingOpenGL2
)

if(NOT VTK_FOUND)
    message(FATAL_ERROR "CylinderExample: Unable to find the VTK build folder.")
endif()

# target configuration
add_executable(CylinderExample CylinderExample.cxx)
target_link_libraries(CylinderExample PRIVATE ${VTK_LIBRARIES})
# vtk_module_autoinit is needed for the GUI to display correctly
vtk_module_autoinit(
    TARGETS CylinderExample
    MODULES ${VTK_LIBRARIES}
)
