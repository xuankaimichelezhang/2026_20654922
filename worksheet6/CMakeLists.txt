cmake_minimum_required(VERSION 3.12)
project(Worksheet6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Try to find Qt6, otherwise try Qt5
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)

# Add the TreeModel directory to includes
include_directories(TreeModel)

# Define the source files
set(SOURCE_FILES
    TreeModel/main.cpp
    TreeModel/ModelPart.cpp
    TreeModel/ModelPart.h
    TreeModel/ModelPartList.cpp
    TreeModel/ModelPartList.h
)

add_executable(Worksheet6 ${SOURCE_FILES})

# Link the Qt libraries
target_link_libraries(Worksheet6 PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)
