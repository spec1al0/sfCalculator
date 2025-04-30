cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDART 17)

project(sfCalculator)

find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/Application.cpp src/Button.cpp src/Label.cpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
