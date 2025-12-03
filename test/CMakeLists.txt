cmake_minimum_required(VERSION 3.16)

project(RhyoliteTest LANGUAGES CXX)

enable_testing()

SET(CMAKE_CXX_STANDARD 23)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.11.0
)

FetchContent_MakeAvailable(Catch2)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

add_executable(RhyoliteTest tst_rhyolitetest.cpp
  tst_rhyolite2dtest.cpp)
target_link_libraries(RhyoliteTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(RhyoliteTest PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(RhyoliteTest PRIVATE Rhyolite)
target_link_libraries(RhyoliteTest PRIVATE Rhyolite2D)


add_test(NAME RhyoliteTest COMMAND RhyoliteTest)
