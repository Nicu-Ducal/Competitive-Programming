# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/dinic_matching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dinic_matching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dinic_matching.dir/flags.make

CMakeFiles/dinic_matching.dir/dinic_matching.cpp.obj: CMakeFiles/dinic_matching.dir/flags.make
CMakeFiles/dinic_matching.dir/dinic_matching.cpp.obj: ../dinic_matching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dinic_matching.dir/dinic_matching.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dinic_matching.dir\dinic_matching.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\dinic_matching.cpp"

CMakeFiles/dinic_matching.dir/dinic_matching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dinic_matching.dir/dinic_matching.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\dinic_matching.cpp" > CMakeFiles\dinic_matching.dir\dinic_matching.cpp.i

CMakeFiles/dinic_matching.dir/dinic_matching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dinic_matching.dir/dinic_matching.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\dinic_matching.cpp" -o CMakeFiles\dinic_matching.dir\dinic_matching.cpp.s

# Object files for target dinic_matching
dinic_matching_OBJECTS = \
"CMakeFiles/dinic_matching.dir/dinic_matching.cpp.obj"

# External object files for target dinic_matching
dinic_matching_EXTERNAL_OBJECTS =

dinic_matching.exe: CMakeFiles/dinic_matching.dir/dinic_matching.cpp.obj
dinic_matching.exe: CMakeFiles/dinic_matching.dir/build.make
dinic_matching.exe: CMakeFiles/dinic_matching.dir/linklibs.rsp
dinic_matching.exe: CMakeFiles/dinic_matching.dir/objects1.rsp
dinic_matching.exe: CMakeFiles/dinic_matching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dinic_matching.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dinic_matching.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dinic_matching.dir/build: dinic_matching.exe

.PHONY : CMakeFiles/dinic_matching.dir/build

CMakeFiles/dinic_matching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dinic_matching.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dinic_matching.dir/clean

CMakeFiles/dinic_matching.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles\dinic_matching.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dinic_matching.dir/depend

