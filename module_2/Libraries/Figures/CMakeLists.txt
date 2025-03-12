cmake_minimum_required(VERSION 3.22.0)

project(figures_DLL_project)

set (SOURCES 
FigureException.cpp 
Figure.cpp 
Triangle.cpp 
Quadrangle.cpp 
EquilateralTriangle.cpp 
IsoscelesTriangle.cpp 
RightAngledTriangle.cpp 
Parallelogram.cpp 
Rectangle.cpp 
Rhomb.cpp 
Square.cpp
)

set (HEADERS
FigureException.h 
Figure.h 
Triangle.h 
Quadrangle.h 
EquilateralTriangle.h 
IsoscelesTriangle.h 
RightAngledTriangle.h 
Parallelogram.h 
Rectangle.h 
Rhomb.h 
Square.h
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(figures_DLL SHARED ${SOURCES} ${HEADERS} FiguresLibrary.h)

add_executable(figures_client Figures.cpp)

target_link_libraries(figures_client figures_DLL)