# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/chase/projects/C/comet-lang/src/linux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chase/projects/C/comet-lang/bin/linux-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.c.o: /home/chase/projects/C/comet-lang/src/linux/main.c
CMakeFiles/main.dir/main.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/main.c.o -MF CMakeFiles/main.dir/main.c.o.d -o CMakeFiles/main.dir/main.c.o -c /home/chase/projects/C/comet-lang/src/linux/main.c

CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/main.c > CMakeFiles/main.dir/main.c.i

CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/main.c -o CMakeFiles/main.dir/main.c.s

CMakeFiles/main.dir/lexer/token.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/lexer/token.c.o: /home/chase/projects/C/comet-lang/src/linux/lexer/token.c
CMakeFiles/main.dir/lexer/token.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/lexer/token.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/lexer/token.c.o -MF CMakeFiles/main.dir/lexer/token.c.o.d -o CMakeFiles/main.dir/lexer/token.c.o -c /home/chase/projects/C/comet-lang/src/linux/lexer/token.c

CMakeFiles/main.dir/lexer/token.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/lexer/token.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/lexer/token.c > CMakeFiles/main.dir/lexer/token.c.i

CMakeFiles/main.dir/lexer/token.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/lexer/token.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/lexer/token.c -o CMakeFiles/main.dir/lexer/token.c.s

CMakeFiles/main.dir/compiler/comet.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/compiler/comet.c.o: /home/chase/projects/C/comet-lang/src/linux/compiler/comet.c
CMakeFiles/main.dir/compiler/comet.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/compiler/comet.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/compiler/comet.c.o -MF CMakeFiles/main.dir/compiler/comet.c.o.d -o CMakeFiles/main.dir/compiler/comet.c.o -c /home/chase/projects/C/comet-lang/src/linux/compiler/comet.c

CMakeFiles/main.dir/compiler/comet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/compiler/comet.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/compiler/comet.c > CMakeFiles/main.dir/compiler/comet.c.i

CMakeFiles/main.dir/compiler/comet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/compiler/comet.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/compiler/comet.c -o CMakeFiles/main.dir/compiler/comet.c.s

CMakeFiles/main.dir/parser/scanner.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/parser/scanner.c.o: /home/chase/projects/C/comet-lang/src/linux/parser/scanner.c
CMakeFiles/main.dir/parser/scanner.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/parser/scanner.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/parser/scanner.c.o -MF CMakeFiles/main.dir/parser/scanner.c.o.d -o CMakeFiles/main.dir/parser/scanner.c.o -c /home/chase/projects/C/comet-lang/src/linux/parser/scanner.c

CMakeFiles/main.dir/parser/scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/parser/scanner.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/parser/scanner.c > CMakeFiles/main.dir/parser/scanner.c.i

CMakeFiles/main.dir/parser/scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/parser/scanner.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/parser/scanner.c -o CMakeFiles/main.dir/parser/scanner.c.s

CMakeFiles/main.dir/util/vector.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/util/vector.c.o: /home/chase/projects/C/comet-lang/src/linux/util/vector.c
CMakeFiles/main.dir/util/vector.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/main.dir/util/vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/util/vector.c.o -MF CMakeFiles/main.dir/util/vector.c.o.d -o CMakeFiles/main.dir/util/vector.c.o -c /home/chase/projects/C/comet-lang/src/linux/util/vector.c

CMakeFiles/main.dir/util/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/util/vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/util/vector.c > CMakeFiles/main.dir/util/vector.c.i

CMakeFiles/main.dir/util/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/util/vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/util/vector.c -o CMakeFiles/main.dir/util/vector.c.s

CMakeFiles/main.dir/util/string_util.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/util/string_util.c.o: /home/chase/projects/C/comet-lang/src/linux/util/string_util.c
CMakeFiles/main.dir/util/string_util.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/main.dir/util/string_util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/util/string_util.c.o -MF CMakeFiles/main.dir/util/string_util.c.o.d -o CMakeFiles/main.dir/util/string_util.c.o -c /home/chase/projects/C/comet-lang/src/linux/util/string_util.c

CMakeFiles/main.dir/util/string_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/util/string_util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chase/projects/C/comet-lang/src/linux/util/string_util.c > CMakeFiles/main.dir/util/string_util.c.i

CMakeFiles/main.dir/util/string_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/util/string_util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chase/projects/C/comet-lang/src/linux/util/string_util.c -o CMakeFiles/main.dir/util/string_util.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/lexer/token.c.o" \
"CMakeFiles/main.dir/compiler/comet.c.o" \
"CMakeFiles/main.dir/parser/scanner.c.o" \
"CMakeFiles/main.dir/util/vector.c.o" \
"CMakeFiles/main.dir/util/string_util.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.c.o
main: CMakeFiles/main.dir/lexer/token.c.o
main: CMakeFiles/main.dir/compiler/comet.c.o
main: CMakeFiles/main.dir/parser/scanner.c.o
main: CMakeFiles/main.dir/util/vector.c.o
main: CMakeFiles/main.dir/util/string_util.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/chase/projects/C/comet-lang/bin/linux-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chase/projects/C/comet-lang/src/linux /home/chase/projects/C/comet-lang/src/linux /home/chase/projects/C/comet-lang/bin/linux-build-debug /home/chase/projects/C/comet-lang/bin/linux-build-debug /home/chase/projects/C/comet-lang/bin/linux-build-debug/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

