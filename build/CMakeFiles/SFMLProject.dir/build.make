# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /Users/lurker/Documents/CMPE126Project/CMPE126Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lurker/Documents/CMPE126Project/CMPE126Project/build

# Include any dependencies generated for this target.
include CMakeFiles/SFMLProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SFMLProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLProject.dir/flags.make

CMakeFiles/SFMLProject.dir/codegen:
.PHONY : CMakeFiles/SFMLProject.dir/codegen

CMakeFiles/SFMLProject.dir/main.cpp.o: CMakeFiles/SFMLProject.dir/flags.make
CMakeFiles/SFMLProject.dir/main.cpp.o: /Users/lurker/Documents/CMPE126Project/CMPE126Project/main.cpp
CMakeFiles/SFMLProject.dir/main.cpp.o: CMakeFiles/SFMLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lurker/Documents/CMPE126Project/CMPE126Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SFMLProject.dir/main.cpp.o -MF CMakeFiles/SFMLProject.dir/main.cpp.o.d -o CMakeFiles/SFMLProject.dir/main.cpp.o -c /Users/lurker/Documents/CMPE126Project/CMPE126Project/main.cpp

CMakeFiles/SFMLProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SFMLProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lurker/Documents/CMPE126Project/CMPE126Project/main.cpp > CMakeFiles/SFMLProject.dir/main.cpp.i

CMakeFiles/SFMLProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SFMLProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lurker/Documents/CMPE126Project/CMPE126Project/main.cpp -o CMakeFiles/SFMLProject.dir/main.cpp.s

# Object files for target SFMLProject
SFMLProject_OBJECTS = \
"CMakeFiles/SFMLProject.dir/main.cpp.o"

# External object files for target SFMLProject
SFMLProject_EXTERNAL_OBJECTS =

bin/SFMLProject: CMakeFiles/SFMLProject.dir/main.cpp.o
bin/SFMLProject: CMakeFiles/SFMLProject.dir/build.make
bin/SFMLProject: /usr/local/lib/libsfml-graphics.2.6.2.dylib
bin/SFMLProject: /usr/local/lib/libsfml-window.2.6.2.dylib
bin/SFMLProject: /usr/local/lib/libsfml-system.2.6.2.dylib
bin/SFMLProject: CMakeFiles/SFMLProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lurker/Documents/CMPE126Project/CMPE126Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/SFMLProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFMLProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLProject.dir/build: bin/SFMLProject
.PHONY : CMakeFiles/SFMLProject.dir/build

CMakeFiles/SFMLProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFMLProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFMLProject.dir/clean

CMakeFiles/SFMLProject.dir/depend:
	cd /Users/lurker/Documents/CMPE126Project/CMPE126Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lurker/Documents/CMPE126Project/CMPE126Project /Users/lurker/Documents/CMPE126Project/CMPE126Project /Users/lurker/Documents/CMPE126Project/CMPE126Project/build /Users/lurker/Documents/CMPE126Project/CMPE126Project/build /Users/lurker/Documents/CMPE126Project/CMPE126Project/build/CMakeFiles/SFMLProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SFMLProject.dir/depend

