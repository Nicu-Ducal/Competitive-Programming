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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/edu98.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/edu98.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/edu98.dir/flags.make

CMakeFiles/edu98.dir/main.cpp.obj: CMakeFiles/edu98.dir/flags.make
CMakeFiles/edu98.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/edu98.dir/main.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\edu98.dir\main.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\main.cpp"

CMakeFiles/edu98.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/edu98.dir/main.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\main.cpp" > CMakeFiles\edu98.dir\main.cpp.i

CMakeFiles/edu98.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/edu98.dir/main.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\main.cpp" -o CMakeFiles\edu98.dir\main.cpp.s

# Object files for target edu98
edu98_OBJECTS = \
"CMakeFiles/edu98.dir/main.cpp.obj"

# External object files for target edu98
edu98_EXTERNAL_OBJECTS =

edu98.exe: CMakeFiles/edu98.dir/main.cpp.obj
edu98.exe: CMakeFiles/edu98.dir/build.make
edu98.exe: CMakeFiles/edu98.dir/linklibs.rsp
edu98.exe: CMakeFiles/edu98.dir/objects1.rsp
edu98.exe: CMakeFiles/edu98.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable edu98.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\edu98.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/edu98.dir/build: edu98.exe

.PHONY : CMakeFiles/edu98.dir/build

CMakeFiles/edu98.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\edu98.dir\cmake_clean.cmake
.PHONY : CMakeFiles/edu98.dir/clean

CMakeFiles/edu98.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\edu98\cmake-build-debug\CMakeFiles\edu98.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/edu98.dir/depend

