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
CMAKE_SOURCE_DIR = /Users/lewis/Desktop/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lewis/Desktop/test/build

# Include any dependencies generated for this target.
include src/week01/CMakeFiles/testprogram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/week01/CMakeFiles/testprogram.dir/compiler_depend.make

# Include the progress variables for this target.
include src/week01/CMakeFiles/testprogram.dir/progress.make

# Include the compile flags for this target's objects.
include src/week01/CMakeFiles/testprogram.dir/flags.make

src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o: src/week01/CMakeFiles/testprogram.dir/flags.make
src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o: /Users/lewis/Desktop/test/src/week01/week01.spec.cpp
src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o: src/week01/CMakeFiles/testprogram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lewis/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o"
	cd /Users/lewis/Desktop/test/build/src/week01 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o -MF CMakeFiles/testprogram.dir/week01.spec.cpp.o.d -o CMakeFiles/testprogram.dir/week01.spec.cpp.o -c /Users/lewis/Desktop/test/src/week01/week01.spec.cpp

src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testprogram.dir/week01.spec.cpp.i"
	cd /Users/lewis/Desktop/test/build/src/week01 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lewis/Desktop/test/src/week01/week01.spec.cpp > CMakeFiles/testprogram.dir/week01.spec.cpp.i

src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testprogram.dir/week01.spec.cpp.s"
	cd /Users/lewis/Desktop/test/build/src/week01 && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lewis/Desktop/test/src/week01/week01.spec.cpp -o CMakeFiles/testprogram.dir/week01.spec.cpp.s

# Object files for target testprogram
testprogram_OBJECTS = \
"CMakeFiles/testprogram.dir/week01.spec.cpp.o"

# External object files for target testprogram
testprogram_EXTERNAL_OBJECTS =

src/week01/testprogram: src/week01/CMakeFiles/testprogram.dir/week01.spec.cpp.o
src/week01/testprogram: src/week01/CMakeFiles/testprogram.dir/build.make
src/week01/testprogram: src/libtestlib.a
src/week01/testprogram: src/week01/CMakeFiles/testprogram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lewis/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testprogram"
	cd /Users/lewis/Desktop/test/build/src/week01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testprogram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/week01/CMakeFiles/testprogram.dir/build: src/week01/testprogram
.PHONY : src/week01/CMakeFiles/testprogram.dir/build

src/week01/CMakeFiles/testprogram.dir/clean:
	cd /Users/lewis/Desktop/test/build/src/week01 && $(CMAKE_COMMAND) -P CMakeFiles/testprogram.dir/cmake_clean.cmake
.PHONY : src/week01/CMakeFiles/testprogram.dir/clean

src/week01/CMakeFiles/testprogram.dir/depend:
	cd /Users/lewis/Desktop/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lewis/Desktop/test /Users/lewis/Desktop/test/src/week01 /Users/lewis/Desktop/test/build /Users/lewis/Desktop/test/build/src/week01 /Users/lewis/Desktop/test/build/src/week01/CMakeFiles/testprogram.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/week01/CMakeFiles/testprogram.dir/depend
