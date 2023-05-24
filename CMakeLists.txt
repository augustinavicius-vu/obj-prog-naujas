cmake_minimum_required(VERSION 3.12)
project(ObjProg)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCES
        main.cpp
        includes/functions.cpp
        includes/menu.cpp
        includes/studentas.cpp)

# Add the header files
set(HEADERS
        includes/menu.h
        includes/calculations.h
        includes/studentas.h)

# Create the executable
add_executable(ObjProg ${SOURCES} ${HEADERS})