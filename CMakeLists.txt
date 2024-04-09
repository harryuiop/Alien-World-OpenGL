cmake_minimum_required(VERSION 2.8)

project(assignment-1)

add_executable(alien-world.out alien-world.cpp textures-service.cpp spaceship.cpp alien.cpp)  # Add textures-service.cpp here

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries( alien-world.out ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
