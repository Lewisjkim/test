# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lewis/Documents/GitHub/cpp-training-jskim/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build

# Include any dependencies generated for this target.
include src/CMakeFiles/testlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/testlib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/testlib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/testlib.dir/flags.make

src/CMakeFiles/testlib.dir/week01/week01.cpp.o: src/CMakeFiles/testlib.dir/flags.make
src/CMakeFiles/testlib.dir/week01/week01.cpp.o: /Users/lewis/Documents/GitHub/cpp-training-jskim/test/src/week01/week01.cpp
src/CMakeFiles/testlib.dir/week01/week01.cpp.o: src/CMakeFiles/testlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/testlib.dir/week01/week01.cpp.o"
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/testlib.dir/week01/week01.cpp.o -MF CMakeFiles/testlib.dir/week01/week01.cpp.o.d -o CMakeFiles/testlib.dir/week01/week01.cpp.o -c /Users/lewis/Documents/GitHub/cpp-training-jskim/test/src/week01/week01.cpp

src/CMakeFiles/testlib.dir/week01/week01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testlib.dir/week01/week01.cpp.i"
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Documents/GitHub/cpp-training-jskim/test/src/week01/week01.cpp > CMakeFiles/testlib.dir/week01/week01.cpp.i

src/CMakeFiles/testlib.dir/week01/week01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testlib.dir/week01/week01.cpp.s"
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Documents/GitHub/cpp-training-jskim/test/src/week01/week01.cpp -o CMakeFiles/testlib.dir/week01/week01.cpp.s

# Object files for target testlib
testlib_OBJECTS = \
"CMakeFiles/testlib.dir/week01/week01.cpp.o"

# External object files for target testlib
testlib_EXTERNAL_OBJECTS =

src/libtestlib.a: src/CMakeFiles/testlib.dir/week01/week01.cpp.o
src/libtestlib.a: src/CMakeFiles/testlib.dir/build.make
src/libtestlib.a: src/CMakeFiles/testlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtestlib.a"
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && $(CMAKE_COMMAND) -P CMakeFiles/testlib.dir/cmake_clean_target.cmake
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/testlib.dir/build: src/libtestlib.a
.PHONY : src/CMakeFiles/testlib.dir/build

src/CMakeFiles/testlib.dir/clean:
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src && $(CMAKE_COMMAND) -P CMakeFiles/testlib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/testlib.dir/clean

src/CMakeFiles/testlib.dir/depend:
	cd /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lewis/Documents/GitHub/cpp-training-jskim/test /Users/lewis/Documents/GitHub/cpp-training-jskim/test/src /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src /Users/lewis/Documents/GitHub/cpp-training-jskim/test/build/src/CMakeFiles/testlib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/testlib.dir/depend

