#CMakeLists de la racine
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
project("CalculScientifique")
add_subdirectory(src)
add_subdirectory(tests)
