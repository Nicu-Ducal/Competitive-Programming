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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Party.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Party.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Party.dir/flags.make

CMakeFiles/Party.dir/Party.cpp.obj: CMakeFiles/Party.dir/flags.make
CMakeFiles/Party.dir/Party.cpp.obj: ../Party.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Party.dir/Party.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Party.dir\Party.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\Party.cpp"

CMakeFiles/Party.dir/Party.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Party.dir/Party.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\Party.cpp" > CMakeFiles\Party.dir\Party.cpp.i

CMakeFiles/Party.dir/Party.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Party.dir/Party.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\Party.cpp" -o CMakeFiles\Party.dir\Party.cpp.s

# Object files for target Party
Party_OBJECTS = \
"CMakeFiles/Party.dir/Party.cpp.obj"

# External object files for target Party
Party_EXTERNAL_OBJECTS =

Party.exe: CMakeFiles/Party.dir/Party.cpp.obj
Party.exe: CMakeFiles/Party.dir/build.make
Party.exe: CMakeFiles/Party.dir/linklibs.rsp
Party.exe: CMakeFiles/Party.dir/objects1.rsp
Party.exe: CMakeFiles/Party.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Party.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Party.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Party.dir/build: Party.exe

.PHONY : CMakeFiles/Party.dir/build

CMakeFiles/Party.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Party.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Party.dir/clean

CMakeFiles/Party.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\Codeforces\Practice\cmake-build-debug\CMakeFiles\Party.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Party.dir/depend

