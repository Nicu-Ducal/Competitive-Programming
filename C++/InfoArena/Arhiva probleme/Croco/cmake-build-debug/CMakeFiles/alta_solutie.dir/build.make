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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/alta_solutie.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alta_solutie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alta_solutie.dir/flags.make

CMakeFiles/alta_solutie.dir/alta_solutie.cpp.obj: CMakeFiles/alta_solutie.dir/flags.make
CMakeFiles/alta_solutie.dir/alta_solutie.cpp.obj: ../alta_solutie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alta_solutie.dir/alta_solutie.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\alta_solutie.dir\alta_solutie.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\alta_solutie.cpp"

CMakeFiles/alta_solutie.dir/alta_solutie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alta_solutie.dir/alta_solutie.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\alta_solutie.cpp" > CMakeFiles\alta_solutie.dir\alta_solutie.cpp.i

CMakeFiles/alta_solutie.dir/alta_solutie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alta_solutie.dir/alta_solutie.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\alta_solutie.cpp" -o CMakeFiles\alta_solutie.dir\alta_solutie.cpp.s

# Object files for target alta_solutie
alta_solutie_OBJECTS = \
"CMakeFiles/alta_solutie.dir/alta_solutie.cpp.obj"

# External object files for target alta_solutie
alta_solutie_EXTERNAL_OBJECTS =

alta_solutie.exe: CMakeFiles/alta_solutie.dir/alta_solutie.cpp.obj
alta_solutie.exe: CMakeFiles/alta_solutie.dir/build.make
alta_solutie.exe: CMakeFiles/alta_solutie.dir/linklibs.rsp
alta_solutie.exe: CMakeFiles/alta_solutie.dir/objects1.rsp
alta_solutie.exe: CMakeFiles/alta_solutie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alta_solutie.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\alta_solutie.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alta_solutie.dir/build: alta_solutie.exe

.PHONY : CMakeFiles/alta_solutie.dir/build

CMakeFiles/alta_solutie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\alta_solutie.dir\cmake_clean.cmake
.PHONY : CMakeFiles/alta_solutie.dir/clean

CMakeFiles/alta_solutie.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Croco\cmake-build-debug\CMakeFiles\alta_solutie.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/alta_solutie.dir/depend

