# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/steak/Documents/GitHub/CUpsilon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/steak/Documents/GitHub/CUpsilon/build

# Include any dependencies generated for this target.
include Source/Base/CMakeFiles/UpsilonBase.dir/depend.make

# Include the progress variables for this target.
include Source/Base/CMakeFiles/UpsilonBase.dir/progress.make

# Include the compile flags for this target's objects.
include Source/Base/CMakeFiles/UpsilonBase.dir/flags.make

Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.o: Source/Base/CMakeFiles/UpsilonBase.dir/flags.make
Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.o: ../Source/Base/Vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/steak/Documents/GitHub/CUpsilon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.o"
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/UpsilonBase.dir/Vector.c.o   -c /home/steak/Documents/GitHub/CUpsilon/Source/Base/Vector.c

Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/UpsilonBase.dir/Vector.c.i"
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/steak/Documents/GitHub/CUpsilon/Source/Base/Vector.c > CMakeFiles/UpsilonBase.dir/Vector.c.i

Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/UpsilonBase.dir/Vector.c.s"
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/steak/Documents/GitHub/CUpsilon/Source/Base/Vector.c -o CMakeFiles/UpsilonBase.dir/Vector.c.s

# Object files for target UpsilonBase
UpsilonBase_OBJECTS = \
"CMakeFiles/UpsilonBase.dir/Vector.c.o"

# External object files for target UpsilonBase
UpsilonBase_EXTERNAL_OBJECTS =

Source/Base/libUpsilonBase.a: Source/Base/CMakeFiles/UpsilonBase.dir/Vector.c.o
Source/Base/libUpsilonBase.a: Source/Base/CMakeFiles/UpsilonBase.dir/build.make
Source/Base/libUpsilonBase.a: Source/Base/CMakeFiles/UpsilonBase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/steak/Documents/GitHub/CUpsilon/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libUpsilonBase.a"
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && $(CMAKE_COMMAND) -P CMakeFiles/UpsilonBase.dir/cmake_clean_target.cmake
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UpsilonBase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Source/Base/CMakeFiles/UpsilonBase.dir/build: Source/Base/libUpsilonBase.a

.PHONY : Source/Base/CMakeFiles/UpsilonBase.dir/build

Source/Base/CMakeFiles/UpsilonBase.dir/clean:
	cd /home/steak/Documents/GitHub/CUpsilon/build/Source/Base && $(CMAKE_COMMAND) -P CMakeFiles/UpsilonBase.dir/cmake_clean.cmake
.PHONY : Source/Base/CMakeFiles/UpsilonBase.dir/clean

Source/Base/CMakeFiles/UpsilonBase.dir/depend:
	cd /home/steak/Documents/GitHub/CUpsilon/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/steak/Documents/GitHub/CUpsilon /home/steak/Documents/GitHub/CUpsilon/Source/Base /home/steak/Documents/GitHub/CUpsilon/build /home/steak/Documents/GitHub/CUpsilon/build/Source/Base /home/steak/Documents/GitHub/CUpsilon/build/Source/Base/CMakeFiles/UpsilonBase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Source/Base/CMakeFiles/UpsilonBase.dir/depend

