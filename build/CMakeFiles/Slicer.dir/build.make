# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/kali/VSCodeProjects/Slicer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/VSCodeProjects/Slicer/build

# Include any dependencies generated for this target.
include CMakeFiles/Slicer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Slicer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Slicer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Slicer.dir/flags.make

CMakeFiles/Slicer.dir/main.cpp.o: CMakeFiles/Slicer.dir/flags.make
CMakeFiles/Slicer.dir/main.cpp.o: /home/kali/VSCodeProjects/Slicer/main.cpp
CMakeFiles/Slicer.dir/main.cpp.o: CMakeFiles/Slicer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/VSCodeProjects/Slicer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Slicer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Slicer.dir/main.cpp.o -MF CMakeFiles/Slicer.dir/main.cpp.o.d -o CMakeFiles/Slicer.dir/main.cpp.o -c /home/kali/VSCodeProjects/Slicer/main.cpp

CMakeFiles/Slicer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Slicer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/VSCodeProjects/Slicer/main.cpp > CMakeFiles/Slicer.dir/main.cpp.i

CMakeFiles/Slicer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Slicer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/VSCodeProjects/Slicer/main.cpp -o CMakeFiles/Slicer.dir/main.cpp.s

CMakeFiles/Slicer.dir/ArgsParser.cpp.o: CMakeFiles/Slicer.dir/flags.make
CMakeFiles/Slicer.dir/ArgsParser.cpp.o: /home/kali/VSCodeProjects/Slicer/ArgsParser.cpp
CMakeFiles/Slicer.dir/ArgsParser.cpp.o: CMakeFiles/Slicer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/VSCodeProjects/Slicer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Slicer.dir/ArgsParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Slicer.dir/ArgsParser.cpp.o -MF CMakeFiles/Slicer.dir/ArgsParser.cpp.o.d -o CMakeFiles/Slicer.dir/ArgsParser.cpp.o -c /home/kali/VSCodeProjects/Slicer/ArgsParser.cpp

CMakeFiles/Slicer.dir/ArgsParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Slicer.dir/ArgsParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/VSCodeProjects/Slicer/ArgsParser.cpp > CMakeFiles/Slicer.dir/ArgsParser.cpp.i

CMakeFiles/Slicer.dir/ArgsParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Slicer.dir/ArgsParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/VSCodeProjects/Slicer/ArgsParser.cpp -o CMakeFiles/Slicer.dir/ArgsParser.cpp.s

CMakeFiles/Slicer.dir/ClientsReader.cpp.o: CMakeFiles/Slicer.dir/flags.make
CMakeFiles/Slicer.dir/ClientsReader.cpp.o: /home/kali/VSCodeProjects/Slicer/ClientsReader.cpp
CMakeFiles/Slicer.dir/ClientsReader.cpp.o: CMakeFiles/Slicer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kali/VSCodeProjects/Slicer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Slicer.dir/ClientsReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Slicer.dir/ClientsReader.cpp.o -MF CMakeFiles/Slicer.dir/ClientsReader.cpp.o.d -o CMakeFiles/Slicer.dir/ClientsReader.cpp.o -c /home/kali/VSCodeProjects/Slicer/ClientsReader.cpp

CMakeFiles/Slicer.dir/ClientsReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Slicer.dir/ClientsReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/VSCodeProjects/Slicer/ClientsReader.cpp > CMakeFiles/Slicer.dir/ClientsReader.cpp.i

CMakeFiles/Slicer.dir/ClientsReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Slicer.dir/ClientsReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/VSCodeProjects/Slicer/ClientsReader.cpp -o CMakeFiles/Slicer.dir/ClientsReader.cpp.s

# Object files for target Slicer
Slicer_OBJECTS = \
"CMakeFiles/Slicer.dir/main.cpp.o" \
"CMakeFiles/Slicer.dir/ArgsParser.cpp.o" \
"CMakeFiles/Slicer.dir/ClientsReader.cpp.o"

# External object files for target Slicer
Slicer_EXTERNAL_OBJECTS =

Slicer: CMakeFiles/Slicer.dir/main.cpp.o
Slicer: CMakeFiles/Slicer.dir/ArgsParser.cpp.o
Slicer: CMakeFiles/Slicer.dir/ClientsReader.cpp.o
Slicer: CMakeFiles/Slicer.dir/build.make
Slicer: CMakeFiles/Slicer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kali/VSCodeProjects/Slicer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Slicer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Slicer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Slicer.dir/build: Slicer
.PHONY : CMakeFiles/Slicer.dir/build

CMakeFiles/Slicer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Slicer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Slicer.dir/clean

CMakeFiles/Slicer.dir/depend:
	cd /home/kali/VSCodeProjects/Slicer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/VSCodeProjects/Slicer /home/kali/VSCodeProjects/Slicer /home/kali/VSCodeProjects/Slicer/build /home/kali/VSCodeProjects/Slicer/build /home/kali/VSCodeProjects/Slicer/build/CMakeFiles/Slicer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Slicer.dir/depend

