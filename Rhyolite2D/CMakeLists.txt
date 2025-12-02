cmake_minimum_required(VERSION 3.16)

project(Rhyolite2D LANGUAGES CXX)

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

add_library(Rhyolite2D SHARED
  Rhyolite2D_global.h
  renderer2d.cpp
  include/rhyolite/2d/renderer2d.h
  include/rhyolite/2d.h
  include/rhyolite/2d/camera.h camera.cpp
  include/rhyolite/2d/cameraentity.h cameraentity.cpp
  include/rhyolite/2d/transform.h transform.cpp

)

target_link_libraries(Rhyolite2D PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(Rhyolite2D PUBLIC Rhyolite)
target_link_libraries(Rhyolite2D PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Rhyolite2D PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Rhyolite2D PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(Rhyolite2D PUBLIC include)
target_include_directories(Rhyolite2D INTERFACE include)

target_compile_definitions(Rhyolite2D PRIVATE RHYOLITE2D_LIBRARY)
