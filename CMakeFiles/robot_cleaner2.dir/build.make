# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilinux/Documents/5TC/RobotCleaner2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilinux/Documents/5TC/RobotCleaner2

# Include any dependencies generated for this target.
include CMakeFiles/robot_cleaner2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/robot_cleaner2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/robot_cleaner2.dir/flags.make

CMakeFiles/robot_cleaner2.dir/src/action.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/action.cpp.o: src/action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/action.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/action.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/action.cpp

CMakeFiles/robot_cleaner2.dir/src/action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/action.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/action.cpp > CMakeFiles/robot_cleaner2.dir/src/action.cpp.i

CMakeFiles/robot_cleaner2.dir/src/action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/action.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/action.cpp -o CMakeFiles/robot_cleaner2.dir/src/action.cpp.s

CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/action.cpp.o


CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o: src/dp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/dp.cpp

CMakeFiles/robot_cleaner2.dir/src/dp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/dp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/dp.cpp > CMakeFiles/robot_cleaner2.dir/src/dp.cpp.i

CMakeFiles/robot_cleaner2.dir/src/dp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/dp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/dp.cpp -o CMakeFiles/robot_cleaner2.dir/src/dp.cpp.s

CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o


CMakeFiles/robot_cleaner2.dir/src/main.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/main.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/main.cpp

CMakeFiles/robot_cleaner2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/main.cpp > CMakeFiles/robot_cleaner2.dir/src/main.cpp.i

CMakeFiles/robot_cleaner2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/main.cpp -o CMakeFiles/robot_cleaner2.dir/src/main.cpp.s

CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/main.cpp.o


CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o: src/montecarlo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/montecarlo.cpp

CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/montecarlo.cpp > CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.i

CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/montecarlo.cpp -o CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.s

CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o


CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o: src/qlearning.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/qlearning.cpp

CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/qlearning.cpp > CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.i

CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/qlearning.cpp -o CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.s

CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o


CMakeFiles/robot_cleaner2.dir/src/state.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/state.cpp.o: src/state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/state.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/state.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/state.cpp

CMakeFiles/robot_cleaner2.dir/src/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/state.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/state.cpp > CMakeFiles/robot_cleaner2.dir/src/state.cpp.i

CMakeFiles/robot_cleaner2.dir/src/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/state.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/state.cpp -o CMakeFiles/robot_cleaner2.dir/src/state.cpp.s

CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/state.cpp.o


CMakeFiles/robot_cleaner2.dir/src/world.cpp.o: CMakeFiles/robot_cleaner2.dir/flags.make
CMakeFiles/robot_cleaner2.dir/src/world.cpp.o: src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/robot_cleaner2.dir/src/world.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/robot_cleaner2.dir/src/world.cpp.o -c /home/lilinux/Documents/5TC/RobotCleaner2/src/world.cpp

CMakeFiles/robot_cleaner2.dir/src/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/robot_cleaner2.dir/src/world.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilinux/Documents/5TC/RobotCleaner2/src/world.cpp > CMakeFiles/robot_cleaner2.dir/src/world.cpp.i

CMakeFiles/robot_cleaner2.dir/src/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/robot_cleaner2.dir/src/world.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilinux/Documents/5TC/RobotCleaner2/src/world.cpp -o CMakeFiles/robot_cleaner2.dir/src/world.cpp.s

CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.requires:

.PHONY : CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.requires

CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.provides: CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.requires
	$(MAKE) -f CMakeFiles/robot_cleaner2.dir/build.make CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.provides.build
.PHONY : CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.provides

CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.provides.build: CMakeFiles/robot_cleaner2.dir/src/world.cpp.o


# Object files for target robot_cleaner2
robot_cleaner2_OBJECTS = \
"CMakeFiles/robot_cleaner2.dir/src/action.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/main.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/state.cpp.o" \
"CMakeFiles/robot_cleaner2.dir/src/world.cpp.o"

# External object files for target robot_cleaner2
robot_cleaner2_EXTERNAL_OBJECTS =

robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/action.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/main.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/state.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/src/world.cpp.o
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/build.make
robot_cleaner2: CMakeFiles/robot_cleaner2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable robot_cleaner2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/robot_cleaner2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/robot_cleaner2.dir/build: robot_cleaner2

.PHONY : CMakeFiles/robot_cleaner2.dir/build

CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/action.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/dp.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/main.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/montecarlo.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/qlearning.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/state.cpp.o.requires
CMakeFiles/robot_cleaner2.dir/requires: CMakeFiles/robot_cleaner2.dir/src/world.cpp.o.requires

.PHONY : CMakeFiles/robot_cleaner2.dir/requires

CMakeFiles/robot_cleaner2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/robot_cleaner2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/robot_cleaner2.dir/clean

CMakeFiles/robot_cleaner2.dir/depend:
	cd /home/lilinux/Documents/5TC/RobotCleaner2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilinux/Documents/5TC/RobotCleaner2 /home/lilinux/Documents/5TC/RobotCleaner2 /home/lilinux/Documents/5TC/RobotCleaner2 /home/lilinux/Documents/5TC/RobotCleaner2 /home/lilinux/Documents/5TC/RobotCleaner2/CMakeFiles/robot_cleaner2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/robot_cleaner2.dir/depend

