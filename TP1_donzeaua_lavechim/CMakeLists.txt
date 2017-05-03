#CMakeLists de la racine
cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
project("CalculScientifique")
#add_subdirectory(src)
add_subdirectory(tests)
#add_subdirectory(src/ocean)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

include_directories(src/ocean)
link_directories(src/ocean) 
add_subdirectory(src/ocean)

include_directories(src)
link_directories(src) 
add_subdirectory(src) 
add_executable(exe src/main.cxx) 

target_link_libraries(exe ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} src ocean)
