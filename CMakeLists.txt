cmake_minimum_required(VERSION 3.10)
project(rotboi)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME "rotboi")

add_executable(${EXECUTABLE_NAME} main.cpp classes/Entity.cpp classes/Entity.h classes/Character.cpp classes/Character.h classes/Arrow.cpp classes/Arrow.h classes/Enemy.cpp classes/Enemy.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()