cmake_minimum_required(VERSION 3.12)
project(objprog)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the Google Test package
add_subdirectory(googletest)

# Specify the include directories
include_directories(
    includes
    src
)

# Add your source files
set(SOURCES
    main.cpp
    src/functions.cpp
    src/studentas.cpp
    src/menu.cpp
)

# Add the header files
set(HEADERS
    includes/studentas.h
    includes/functions.h
    includes/menu.h
)

# Add the test source files
set(TEST_SOURCES
    test.cpp
)

# Create the executable for your project
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link your project with Google Test
target_link_libraries(${PROJECT_NAME} gtest_main)

# Create the test executable
add_executable(tests ${TEST_SOURCES} ${HEADERS})

# Link the test executable with Google Test
target_link_libraries(tests gtest_main)

# Optional: Add a custom test target for running tests conveniently
add_custom_target(run_tests COMMAND tests)