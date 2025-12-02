cmake_minimum_required(VERSION 3.16)

project(ECSTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ECSTest tst_ecstest.cpp)
add_test(NAME ECSTest COMMAND ECSTest)

target_link_libraries(ECSTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(ECSTest PRIVATE Rhyolite)

