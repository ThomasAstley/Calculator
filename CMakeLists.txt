cmake_minimum_required(VERSION 3.16)

project(Calculator VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/msvc2019_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

qt_standard_project_setup()


include(CTest)
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

set(SOURCES
    src/mainwindow.cpp
)

add_library(MyProjectLib ${SOURCES})

target_link_libraries(MyProjectLib PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)