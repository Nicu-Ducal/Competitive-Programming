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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/edu97.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/edu97.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/edu97.dir/flags.make

CMakeFiles/edu97.dir/main.cpp.obj: CMakeFiles/edu97.dir/flags.make
CMakeFiles/edu97.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/edu97.dir/main.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\edu97.dir\main.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\main.cpp"

CMakeFiles/edu97.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/edu97.dir/main.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\main.cpp" > CMakeFiles\edu97.dir\main.cpp.i

CMakeFiles/edu97.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/edu97.dir/main.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\main.cpp" -o CMakeFiles\edu97.dir\main.cpp.s

# Object files for target edu97
edu97_OBJECTS = \
"CMakeFiles/edu97.dir/main.cpp.obj"

# External object files for target edu97
edu97_EXTERNAL_OBJECTS =

edu97.exe: CMakeFiles/edu97.dir/main.cpp.obj
edu97.exe: CMakeFiles/edu97.dir/build.make
edu97.exe: CMakeFiles/edu97.dir/linklibs.rsp
edu97.exe: CMakeFiles/edu97.dir/objects1.rsp
edu97.exe: CMakeFiles/edu97.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable edu97.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\edu97.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/edu97.dir/build: edu97.exe

.PHONY : CMakeFiles/edu97.dir/build

CMakeFiles/edu97.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\edu97.dir\cmake_clean.cmake
.PHONY : CMakeFiles/edu97.dir/clean

CMakeFiles/edu97.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu97\cmake-build-debug\CMakeFiles\edu97.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/edu97.dir/depend

