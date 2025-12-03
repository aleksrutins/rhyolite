cmake_minimum_required(VERSION 3.16)

project(example LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)

add_executable(example
  main.cpp
)
target_link_libraries(example PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(example PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(example PRIVATE Rhyolite Rhyolite2D)

include(GNUInstallDirs)
install(TARGETS example
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
