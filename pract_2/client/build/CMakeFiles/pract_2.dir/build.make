# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/fume/projects/Qt/PCSS/pract_2/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fume/projects/Qt/PCSS/pract_2/client/build

# Include any dependencies generated for this target.
include CMakeFiles/pract_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pract_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pract_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pract_2.dir/flags.make

CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o: CMakeFiles/pract_2.dir/flags.make
CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o: pract_2_autogen/mocs_compilation.cpp
CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o: CMakeFiles/pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o -MF CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o -c /home/fume/projects/Qt/PCSS/pract_2/client/build/pract_2_autogen/mocs_compilation.cpp

CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fume/projects/Qt/PCSS/pract_2/client/build/pract_2_autogen/mocs_compilation.cpp > CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.i

CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fume/projects/Qt/PCSS/pract_2/client/build/pract_2_autogen/mocs_compilation.cpp -o CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.s

CMakeFiles/pract_2.dir/main.cpp.o: CMakeFiles/pract_2.dir/flags.make
CMakeFiles/pract_2.dir/main.cpp.o: /home/fume/projects/Qt/PCSS/pract_2/client/main.cpp
CMakeFiles/pract_2.dir/main.cpp.o: CMakeFiles/pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pract_2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pract_2.dir/main.cpp.o -MF CMakeFiles/pract_2.dir/main.cpp.o.d -o CMakeFiles/pract_2.dir/main.cpp.o -c /home/fume/projects/Qt/PCSS/pract_2/client/main.cpp

CMakeFiles/pract_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pract_2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fume/projects/Qt/PCSS/pract_2/client/main.cpp > CMakeFiles/pract_2.dir/main.cpp.i

CMakeFiles/pract_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pract_2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fume/projects/Qt/PCSS/pract_2/client/main.cpp -o CMakeFiles/pract_2.dir/main.cpp.s

CMakeFiles/pract_2.dir/mainwindow.cpp.o: CMakeFiles/pract_2.dir/flags.make
CMakeFiles/pract_2.dir/mainwindow.cpp.o: /home/fume/projects/Qt/PCSS/pract_2/client/mainwindow.cpp
CMakeFiles/pract_2.dir/mainwindow.cpp.o: CMakeFiles/pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pract_2.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pract_2.dir/mainwindow.cpp.o -MF CMakeFiles/pract_2.dir/mainwindow.cpp.o.d -o CMakeFiles/pract_2.dir/mainwindow.cpp.o -c /home/fume/projects/Qt/PCSS/pract_2/client/mainwindow.cpp

CMakeFiles/pract_2.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pract_2.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fume/projects/Qt/PCSS/pract_2/client/mainwindow.cpp > CMakeFiles/pract_2.dir/mainwindow.cpp.i

CMakeFiles/pract_2.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pract_2.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fume/projects/Qt/PCSS/pract_2/client/mainwindow.cpp -o CMakeFiles/pract_2.dir/mainwindow.cpp.s

CMakeFiles/pract_2.dir/requests.cpp.o: CMakeFiles/pract_2.dir/flags.make
CMakeFiles/pract_2.dir/requests.cpp.o: /home/fume/projects/Qt/PCSS/pract_2/client/requests.cpp
CMakeFiles/pract_2.dir/requests.cpp.o: CMakeFiles/pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pract_2.dir/requests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pract_2.dir/requests.cpp.o -MF CMakeFiles/pract_2.dir/requests.cpp.o.d -o CMakeFiles/pract_2.dir/requests.cpp.o -c /home/fume/projects/Qt/PCSS/pract_2/client/requests.cpp

CMakeFiles/pract_2.dir/requests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pract_2.dir/requests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fume/projects/Qt/PCSS/pract_2/client/requests.cpp > CMakeFiles/pract_2.dir/requests.cpp.i

CMakeFiles/pract_2.dir/requests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pract_2.dir/requests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fume/projects/Qt/PCSS/pract_2/client/requests.cpp -o CMakeFiles/pract_2.dir/requests.cpp.s

# Object files for target pract_2
pract_2_OBJECTS = \
"CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/pract_2.dir/main.cpp.o" \
"CMakeFiles/pract_2.dir/mainwindow.cpp.o" \
"CMakeFiles/pract_2.dir/requests.cpp.o"

# External object files for target pract_2
pract_2_EXTERNAL_OBJECTS =

pract_2: CMakeFiles/pract_2.dir/pract_2_autogen/mocs_compilation.cpp.o
pract_2: CMakeFiles/pract_2.dir/main.cpp.o
pract_2: CMakeFiles/pract_2.dir/mainwindow.cpp.o
pract_2: CMakeFiles/pract_2.dir/requests.cpp.o
pract_2: CMakeFiles/pract_2.dir/build.make
pract_2: /home/fume/anaconda3/lib/libQt5Widgets.so.5.15.2
pract_2: /home/fume/anaconda3/lib/libQt5Network.so.5.15.2
pract_2: /home/fume/boost_1_80_0/stage/lib/libboost_system.a
pract_2: /home/fume/boost_1_80_0/stage/lib/libboost_program_options.a
pract_2: /home/fume/anaconda3/lib/libQt5Gui.so.5.15.2
pract_2: /home/fume/anaconda3/lib/libQt5Core.so.5.15.2
pract_2: CMakeFiles/pract_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable pract_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pract_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pract_2.dir/build: pract_2
.PHONY : CMakeFiles/pract_2.dir/build

CMakeFiles/pract_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pract_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pract_2.dir/clean

CMakeFiles/pract_2.dir/depend:
	cd /home/fume/projects/Qt/PCSS/pract_2/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fume/projects/Qt/PCSS/pract_2/client /home/fume/projects/Qt/PCSS/pract_2/client /home/fume/projects/Qt/PCSS/pract_2/client/build /home/fume/projects/Qt/PCSS/pract_2/client/build /home/fume/projects/Qt/PCSS/pract_2/client/build/CMakeFiles/pract_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pract_2.dir/depend
