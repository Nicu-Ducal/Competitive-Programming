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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/mincostmatching.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mincostmatching.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mincostmatching.dir/flags.make

CMakeFiles/mincostmatching.dir/mincostmatching.cpp.obj: CMakeFiles/mincostmatching.dir/flags.make
CMakeFiles/mincostmatching.dir/mincostmatching.cpp.obj: ../mincostmatching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mincostmatching.dir/mincostmatching.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mincostmatching.dir\mincostmatching.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\mincostmatching.cpp"

CMakeFiles/mincostmatching.dir/mincostmatching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mincostmatching.dir/mincostmatching.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\mincostmatching.cpp" > CMakeFiles\mincostmatching.dir\mincostmatching.cpp.i

CMakeFiles/mincostmatching.dir/mincostmatching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mincostmatching.dir/mincostmatching.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\mincostmatching.cpp" -o CMakeFiles\mincostmatching.dir\mincostmatching.cpp.s

# Object files for target mincostmatching
mincostmatching_OBJECTS = \
"CMakeFiles/mincostmatching.dir/mincostmatching.cpp.obj"

# External object files for target mincostmatching
mincostmatching_EXTERNAL_OBJECTS =

mincostmatching.exe: CMakeFiles/mincostmatching.dir/mincostmatching.cpp.obj
mincostmatching.exe: CMakeFiles/mincostmatching.dir/build.make
mincostmatching.exe: CMakeFiles/mincostmatching.dir/linklibs.rsp
mincostmatching.exe: CMakeFiles/mincostmatching.dir/objects1.rsp
mincostmatching.exe: CMakeFiles/mincostmatching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mincostmatching.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mincostmatching.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mincostmatching.dir/build: mincostmatching.exe

.PHONY : CMakeFiles/mincostmatching.dir/build

CMakeFiles/mincostmatching.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mincostmatching.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mincostmatching.dir/clean

CMakeFiles/mincostmatching.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim de cost minim\cmake-build-debug\CMakeFiles\mincostmatching.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mincostmatching.dir/depend

