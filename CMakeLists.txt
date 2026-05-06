cmake_minimum_required(VERSION 3.28)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_library(ShapesLibrary STATIC)

target_sources(ShapesLibrary PUBLIC
        FILE_SET CXX_MODULES FILES
        shapes/modules/Figure.cppm
        shapes/modules/Circle.cppm
        shapes/modules/IsoscelesTriangle.cppm
        shapes/modules/ComplexFigure.cppm
        shapes/modules/CanvasWidget.cppm
        shapes/Shapes.cppm
)

target_sources(ShapesLibrary PRIVATE
        shapes/src/Figure.cpp
        shapes/src/Circle.cpp
        shapes/src/IsoscelesTriangle.cpp
        shapes/src/ComplexFigure.cpp
        shapes/src/CanvasWidget.cpp
)

target_link_libraries(ShapesLibrary PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(cpp main.cpp)
target_link_libraries(cpp PRIVATE ShapesLibrary)

add_executable(unit_tests tests/tests.cpp)
target_link_libraries(unit_tests PRIVATE ShapesLibrary)