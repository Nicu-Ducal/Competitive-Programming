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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/b.dir/flags.make

CMakeFiles/b.dir/b.cpp.obj: CMakeFiles/b.dir/flags.make
CMakeFiles/b.dir/b.cpp.obj: ../b.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/b.dir/b.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\b.dir\b.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\b.cpp"

CMakeFiles/b.dir/b.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/b.dir/b.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\b.cpp" > CMakeFiles\b.dir\b.cpp.i

CMakeFiles/b.dir/b.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/b.dir/b.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\b.cpp" -o CMakeFiles\b.dir\b.cpp.s

# Object files for target b
b_OBJECTS = \
"CMakeFiles/b.dir/b.cpp.obj"

# External object files for target b
b_EXTERNAL_OBJECTS =

b.exe: CMakeFiles/b.dir/b.cpp.obj
b.exe: CMakeFiles/b.dir/build.make
b.exe: CMakeFiles/b.dir/linklibs.rsp
b.exe: CMakeFiles/b.dir/objects1.rsp
b.exe: CMakeFiles/b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable b.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\b.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/b.dir/build: b.exe

.PHONY : CMakeFiles/b.dir/build

CMakeFiles/b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\b.dir\cmake_clean.cmake
.PHONY : CMakeFiles/b.dir/clean

CMakeFiles/b.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\cf-702\cmake-build-debug\CMakeFiles\b.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/b.dir/depend

