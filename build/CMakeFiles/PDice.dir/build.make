# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/changjiuli/toys/PDice/posb_dices

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/changjiuli/toys/PDice/build

# Include any dependencies generated for this target.
include CMakeFiles/PDice.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PDice.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PDice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PDice.dir/flags.make

CMakeFiles/PDice.dir/main.cpp.o: CMakeFiles/PDice.dir/flags.make
CMakeFiles/PDice.dir/main.cpp.o: /home/changjiuli/toys/PDice/posb_dices/main.cpp
CMakeFiles/PDice.dir/main.cpp.o: CMakeFiles/PDice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/changjiuli/toys/PDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PDice.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PDice.dir/main.cpp.o -MF CMakeFiles/PDice.dir/main.cpp.o.d -o CMakeFiles/PDice.dir/main.cpp.o -c /home/changjiuli/toys/PDice/posb_dices/main.cpp

CMakeFiles/PDice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PDice.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/changjiuli/toys/PDice/posb_dices/main.cpp > CMakeFiles/PDice.dir/main.cpp.i

CMakeFiles/PDice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PDice.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/changjiuli/toys/PDice/posb_dices/main.cpp -o CMakeFiles/PDice.dir/main.cpp.s

CMakeFiles/PDice.dir/dice.cpp.o: CMakeFiles/PDice.dir/flags.make
CMakeFiles/PDice.dir/dice.cpp.o: /home/changjiuli/toys/PDice/posb_dices/dice.cpp
CMakeFiles/PDice.dir/dice.cpp.o: CMakeFiles/PDice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/changjiuli/toys/PDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PDice.dir/dice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PDice.dir/dice.cpp.o -MF CMakeFiles/PDice.dir/dice.cpp.o.d -o CMakeFiles/PDice.dir/dice.cpp.o -c /home/changjiuli/toys/PDice/posb_dices/dice.cpp

CMakeFiles/PDice.dir/dice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PDice.dir/dice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/changjiuli/toys/PDice/posb_dices/dice.cpp > CMakeFiles/PDice.dir/dice.cpp.i

CMakeFiles/PDice.dir/dice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PDice.dir/dice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/changjiuli/toys/PDice/posb_dices/dice.cpp -o CMakeFiles/PDice.dir/dice.cpp.s

# Object files for target PDice
PDice_OBJECTS = \
"CMakeFiles/PDice.dir/main.cpp.o" \
"CMakeFiles/PDice.dir/dice.cpp.o"

# External object files for target PDice
PDice_EXTERNAL_OBJECTS =

PDice: CMakeFiles/PDice.dir/main.cpp.o
PDice: CMakeFiles/PDice.dir/dice.cpp.o
PDice: CMakeFiles/PDice.dir/build.make
PDice: CMakeFiles/PDice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/changjiuli/toys/PDice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PDice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PDice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PDice.dir/build: PDice
.PHONY : CMakeFiles/PDice.dir/build

CMakeFiles/PDice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PDice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PDice.dir/clean

CMakeFiles/PDice.dir/depend:
	cd /home/changjiuli/toys/PDice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/changjiuli/toys/PDice/posb_dices /home/changjiuli/toys/PDice/posb_dices /home/changjiuli/toys/PDice/build /home/changjiuli/toys/PDice/build /home/changjiuli/toys/PDice/build/CMakeFiles/PDice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PDice.dir/depend

