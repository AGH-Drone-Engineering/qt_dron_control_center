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
CMAKE_SOURCE_DIR = /home/wiktoro/Studia/QT/droniada3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug

# Utility rule file for droniada3_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/droniada3_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/droniada3_autogen.dir/progress.make

CMakeFiles/droniada3_autogen: droniada3_autogen/timestamp

droniada3_autogen/timestamp: /home/wiktoro/Qt/6.6.3/gcc_64/./libexec/moc
droniada3_autogen/timestamp: /home/wiktoro/Qt/6.6.3/gcc_64/./libexec/uic
droniada3_autogen/timestamp: CMakeFiles/droniada3_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target droniada3"
	/usr/bin/cmake -E cmake_autogen /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug/CMakeFiles/droniada3_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug/droniada3_autogen/timestamp

droniada3_autogen: CMakeFiles/droniada3_autogen
droniada3_autogen: droniada3_autogen/timestamp
droniada3_autogen: CMakeFiles/droniada3_autogen.dir/build.make
.PHONY : droniada3_autogen

# Rule to build all files generated by this target.
CMakeFiles/droniada3_autogen.dir/build: droniada3_autogen
.PHONY : CMakeFiles/droniada3_autogen.dir/build

CMakeFiles/droniada3_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/droniada3_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/droniada3_autogen.dir/clean

CMakeFiles/droniada3_autogen.dir/depend:
	cd /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wiktoro/Studia/QT/droniada3 /home/wiktoro/Studia/QT/droniada3 /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug /home/wiktoro/Studia/QT/droniada3/build/Desktop_Qt_6_6_3_GCC_64bit-Debug/CMakeFiles/droniada3_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/droniada3_autogen.dir/depend

