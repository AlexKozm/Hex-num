# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/alex/Mephi/sem3/Infa/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Mephi/sem3/Infa/lab3/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lab3_run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/lab3_run.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lab3_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lab3_run.dir/flags.make

src/CMakeFiles/lab3_run.dir/main.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/lab3_run.dir/main.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lab3_run.dir/main.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/main.cpp.o -MF CMakeFiles/lab3_run.dir/main.cpp.o.d -o CMakeFiles/lab3_run.dir/main.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/main.cpp

src/CMakeFiles/lab3_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/main.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/main.cpp > CMakeFiles/lab3_run.dir/main.cpp.i

src/CMakeFiles/lab3_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/main.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/main.cpp -o CMakeFiles/lab3_run.dir/main.cpp.s

src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o: ../src/Hex_num/base/hex_num_abstract.cpp
src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o -MF CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o.d -o CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/base/hex_num_abstract.cpp

src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/base/hex_num_abstract.cpp > CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.i

src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/base/hex_num_abstract.cpp -o CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.s

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o: ../src/Hex_num/dynamic/hex_num_dynamic.cpp
src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o -MF CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o.d -o CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/hex_num_dynamic.cpp

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/hex_num_dynamic.cpp > CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.i

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/hex_num_dynamic.cpp -o CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.s

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o: ../src/Hex_num/dynamic/overl_dyn_hex_num.cpp
src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o -MF CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o.d -o CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/overl_dyn_hex_num.cpp

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/overl_dyn_hex_num.cpp > CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.i

src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/dynamic/overl_dyn_hex_num.cpp -o CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.s

src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o: ../src/Hex_num/static/stat_hex_num.cpp
src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o -MF CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o.d -o CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/stat_hex_num.cpp

src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/stat_hex_num.cpp > CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.i

src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/stat_hex_num.cpp -o CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.s

src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o: ../src/Hex_num/static/overl_stat_hex_num.cpp
src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o -MF CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o.d -o CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/overl_stat_hex_num.cpp

src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/overl_stat_hex_num.cpp > CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.i

src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/Hex_num/static/overl_stat_hex_num.cpp -o CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.s

src/CMakeFiles/lab3_run.dir/menu.cpp.o: src/CMakeFiles/lab3_run.dir/flags.make
src/CMakeFiles/lab3_run.dir/menu.cpp.o: ../src/menu.cpp
src/CMakeFiles/lab3_run.dir/menu.cpp.o: src/CMakeFiles/lab3_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/lab3_run.dir/menu.cpp.o"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lab3_run.dir/menu.cpp.o -MF CMakeFiles/lab3_run.dir/menu.cpp.o.d -o CMakeFiles/lab3_run.dir/menu.cpp.o -c /home/alex/Mephi/sem3/Infa/lab3/src/menu.cpp

src/CMakeFiles/lab3_run.dir/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_run.dir/menu.cpp.i"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Mephi/sem3/Infa/lab3/src/menu.cpp > CMakeFiles/lab3_run.dir/menu.cpp.i

src/CMakeFiles/lab3_run.dir/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_run.dir/menu.cpp.s"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Mephi/sem3/Infa/lab3/src/menu.cpp -o CMakeFiles/lab3_run.dir/menu.cpp.s

# Object files for target lab3_run
lab3_run_OBJECTS = \
"CMakeFiles/lab3_run.dir/main.cpp.o" \
"CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o" \
"CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o" \
"CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o" \
"CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o" \
"CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o" \
"CMakeFiles/lab3_run.dir/menu.cpp.o"

# External object files for target lab3_run
lab3_run_EXTERNAL_OBJECTS =

src/lab3_run: src/CMakeFiles/lab3_run.dir/main.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/Hex_num/base/hex_num_abstract.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/hex_num_dynamic.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/Hex_num/dynamic/overl_dyn_hex_num.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/Hex_num/static/stat_hex_num.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/Hex_num/static/overl_stat_hex_num.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/menu.cpp.o
src/lab3_run: src/CMakeFiles/lab3_run.dir/build.make
src/lab3_run: src/CMakeFiles/lab3_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Mephi/sem3/Infa/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable lab3_run"
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lab3_run.dir/build: src/lab3_run
.PHONY : src/CMakeFiles/lab3_run.dir/build

src/CMakeFiles/lab3_run.dir/clean:
	cd /home/alex/Mephi/sem3/Infa/lab3/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lab3_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lab3_run.dir/clean

src/CMakeFiles/lab3_run.dir/depend:
	cd /home/alex/Mephi/sem3/Infa/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Mephi/sem3/Infa/lab3 /home/alex/Mephi/sem3/Infa/lab3/src /home/alex/Mephi/sem3/Infa/lab3/build /home/alex/Mephi/sem3/Infa/lab3/build/src /home/alex/Mephi/sem3/Infa/lab3/build/src/CMakeFiles/lab3_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lab3_run.dir/depend

