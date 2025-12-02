cmake_minimum_required(VERSION 3.16)

project(rhyolite LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(rhyolite STATIC
  scene.cpp
  include/rhyolite/scene.h
  include/rhyolite/entity.h entity.cpp
  include/rhyolite/component.h component.cpp
  include/rhyolite/system.h system.cpp
  include/rhyolite/game.h game.cpp
  include/rhyolite/core.h
)

target_link_libraries(rhyolite PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(rhyolite PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(rhyolite PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(rhyolite PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(rhyolite PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(rhyolite INTERFACE include)

target_compile_definitions(rhyolite PRIVATE RHYOLITE_LIBRARY)
add_subdirectory(test)
