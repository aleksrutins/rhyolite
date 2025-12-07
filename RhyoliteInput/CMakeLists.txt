cmake_minimum_required(VERSION 3.16)

project(RhyoliteInput LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(RhyoliteInput SHARED
  RhyoliteInput_global.h
  include/rhyolite/input/inputhandler.h inputhandler.cpp
  include/rhyolite/input.h


)

target_include_directories(RhyoliteInput PUBLIC include)
target_include_directories(RhyoliteInput INTERFACE include)

target_link_libraries(RhyoliteInput PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(RhyoliteInput PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(RhyoliteInput PRIVATE RHYOLITEINPUT_LIBRARY)
