cmake_minimum_required(VERSION 3.12)
project(ObjProg)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCES
        main.cpp
        includes/calculations.cpp
        includes/functions.cpp
        includes/menu.cpp)

# Add the header files
set(HEADERS
        includes/menu.h
        includes/calculations.h
        includes/functions.h
        includes/studentas.h)

# Create the executable
add_executable(ObjProg ${SOURCES} ${HEADERS})