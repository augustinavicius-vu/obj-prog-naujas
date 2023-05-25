cmake_minimum_required(VERSION 3.12)
project(objprog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(googletest)


include_directories(
    includes
    src
)


set(SOURCES
    main.cpp
    src/functions.cpp
    src/studentas.cpp
    src/menu.cpp
)
set(HEADERS
    includes/studentas.h
    includes/functions.h
    includes/menu.h
)
set(TEST_SOURCES
    test.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} gtest_main)

add_executable(tests ${TEST_SOURCES} ${HEADERS})
target_link_libraries(tests gtest_main)

add_custom_target(run_tests COMMAND tests)