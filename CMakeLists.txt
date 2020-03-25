cmake_minimum_required(VERSION 3.15)

project(PatternCreator)

set(CMAKE_CXX_STANDARD 17)

add_executable(PatternCreator main.cpp Geometry/Vertex2D.cpp Geometry/Vertex2D.hpp Geometry/Shape2D.cpp Geometry/Shape2D.hpp GraphicalDebug/GShape2D.cpp GraphicalDebug/GShape2D.hpp Parser/Parser.cpp Parser/Parser.hpp Geometry/EntityShape2D.cpp Geometry/EntityShape2D.hpp)

target_link_libraries(PatternCreator sfml-system sfml-graphics sfml-window)