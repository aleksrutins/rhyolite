cmake_minimum_required(VERSION 3.16)

project(RhyoliteMath LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(RhyoliteMath SHARED
  RhyoliteMath_global.h
  util.cpp
  include/rhyolite/math/util.h
  include/rhyolite/math.h
)

target_link_libraries(RhyoliteMath PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(RhyoliteMath PUBLIC include)
target_include_directories(RhyoliteMath INTERFACE include)

target_compile_definitions(RhyoliteMath PRIVATE RHYOLITEMATH_LIBRARY)
