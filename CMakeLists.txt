cmake_minimum_required(VERSION 3.12)
project(ObjProg)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

include_directories(includes)

set(SOURCES
        includes/functions.cpp
        includes/menu.cpp
        includes/studentas.cpp)

set(HEADERS
        includes/menu.h
        includes/functions.h
        includes/studentas.h)

set(TEST_SOURCES
    test.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} gtest_main)

add_executable(tests ${TEST_SOURCES} ${HEADERS})

target_link_libraries(tests gtest_main)

add_custom_target(run_tests COMMAND tests)