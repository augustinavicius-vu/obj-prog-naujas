# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/code/obj-prog-naujas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/obj-prog-naujas

# Include any dependencies generated for this target.
include CMakeFiles/objprog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/objprog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/objprog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/objprog.dir/flags.make

CMakeFiles/objprog.dir/main.cpp.o: CMakeFiles/objprog.dir/flags.make
CMakeFiles/objprog.dir/main.cpp.o: main.cpp
CMakeFiles/objprog.dir/main.cpp.o: CMakeFiles/objprog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/obj-prog-naujas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/objprog.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/objprog.dir/main.cpp.o -MF CMakeFiles/objprog.dir/main.cpp.o.d -o CMakeFiles/objprog.dir/main.cpp.o -c /home/code/obj-prog-naujas/main.cpp

CMakeFiles/objprog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objprog.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/obj-prog-naujas/main.cpp > CMakeFiles/objprog.dir/main.cpp.i

CMakeFiles/objprog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objprog.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/obj-prog-naujas/main.cpp -o CMakeFiles/objprog.dir/main.cpp.s

CMakeFiles/objprog.dir/src/functions.cpp.o: CMakeFiles/objprog.dir/flags.make
CMakeFiles/objprog.dir/src/functions.cpp.o: src/functions.cpp
CMakeFiles/objprog.dir/src/functions.cpp.o: CMakeFiles/objprog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/obj-prog-naujas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/objprog.dir/src/functions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/objprog.dir/src/functions.cpp.o -MF CMakeFiles/objprog.dir/src/functions.cpp.o.d -o CMakeFiles/objprog.dir/src/functions.cpp.o -c /home/code/obj-prog-naujas/src/functions.cpp

CMakeFiles/objprog.dir/src/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objprog.dir/src/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/obj-prog-naujas/src/functions.cpp > CMakeFiles/objprog.dir/src/functions.cpp.i

CMakeFiles/objprog.dir/src/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objprog.dir/src/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/obj-prog-naujas/src/functions.cpp -o CMakeFiles/objprog.dir/src/functions.cpp.s

CMakeFiles/objprog.dir/src/studentas.cpp.o: CMakeFiles/objprog.dir/flags.make
CMakeFiles/objprog.dir/src/studentas.cpp.o: src/studentas.cpp
CMakeFiles/objprog.dir/src/studentas.cpp.o: CMakeFiles/objprog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/obj-prog-naujas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/objprog.dir/src/studentas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/objprog.dir/src/studentas.cpp.o -MF CMakeFiles/objprog.dir/src/studentas.cpp.o.d -o CMakeFiles/objprog.dir/src/studentas.cpp.o -c /home/code/obj-prog-naujas/src/studentas.cpp

CMakeFiles/objprog.dir/src/studentas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objprog.dir/src/studentas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/obj-prog-naujas/src/studentas.cpp > CMakeFiles/objprog.dir/src/studentas.cpp.i

CMakeFiles/objprog.dir/src/studentas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objprog.dir/src/studentas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/obj-prog-naujas/src/studentas.cpp -o CMakeFiles/objprog.dir/src/studentas.cpp.s

CMakeFiles/objprog.dir/src/menu.cpp.o: CMakeFiles/objprog.dir/flags.make
CMakeFiles/objprog.dir/src/menu.cpp.o: src/menu.cpp
CMakeFiles/objprog.dir/src/menu.cpp.o: CMakeFiles/objprog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/obj-prog-naujas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/objprog.dir/src/menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/objprog.dir/src/menu.cpp.o -MF CMakeFiles/objprog.dir/src/menu.cpp.o.d -o CMakeFiles/objprog.dir/src/menu.cpp.o -c /home/code/obj-prog-naujas/src/menu.cpp

CMakeFiles/objprog.dir/src/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objprog.dir/src/menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/obj-prog-naujas/src/menu.cpp > CMakeFiles/objprog.dir/src/menu.cpp.i

CMakeFiles/objprog.dir/src/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objprog.dir/src/menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/obj-prog-naujas/src/menu.cpp -o CMakeFiles/objprog.dir/src/menu.cpp.s

# Object files for target objprog
objprog_OBJECTS = \
"CMakeFiles/objprog.dir/main.cpp.o" \
"CMakeFiles/objprog.dir/src/functions.cpp.o" \
"CMakeFiles/objprog.dir/src/studentas.cpp.o" \
"CMakeFiles/objprog.dir/src/menu.cpp.o"

# External object files for target objprog
objprog_EXTERNAL_OBJECTS =

objprog: CMakeFiles/objprog.dir/main.cpp.o
objprog: CMakeFiles/objprog.dir/src/functions.cpp.o
objprog: CMakeFiles/objprog.dir/src/studentas.cpp.o
objprog: CMakeFiles/objprog.dir/src/menu.cpp.o
objprog: CMakeFiles/objprog.dir/build.make
objprog: lib/libgtest_main.a
objprog: lib/libgtest.a
objprog: CMakeFiles/objprog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/obj-prog-naujas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable objprog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/objprog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/objprog.dir/build: objprog
.PHONY : CMakeFiles/objprog.dir/build

CMakeFiles/objprog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/objprog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/objprog.dir/clean

CMakeFiles/objprog.dir/depend:
	cd /home/code/obj-prog-naujas && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/obj-prog-naujas /home/code/obj-prog-naujas /home/code/obj-prog-naujas /home/code/obj-prog-naujas /home/code/obj-prog-naujas/CMakeFiles/objprog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/objprog.dir/depend

