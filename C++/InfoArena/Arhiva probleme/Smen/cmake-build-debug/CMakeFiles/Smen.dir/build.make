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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Smen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Smen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Smen.dir/flags.make

CMakeFiles/Smen.dir/main.cpp.obj: CMakeFiles/Smen.dir/flags.make
CMakeFiles/Smen.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Smen.dir/main.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Smen.dir\main.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\main.cpp"

CMakeFiles/Smen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smen.dir/main.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\main.cpp" > CMakeFiles\Smen.dir\main.cpp.i

CMakeFiles/Smen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smen.dir/main.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\main.cpp" -o CMakeFiles\Smen.dir\main.cpp.s

# Object files for target Smen
Smen_OBJECTS = \
"CMakeFiles/Smen.dir/main.cpp.obj"

# External object files for target Smen
Smen_EXTERNAL_OBJECTS =

Smen.exe: CMakeFiles/Smen.dir/main.cpp.obj
Smen.exe: CMakeFiles/Smen.dir/build.make
Smen.exe: CMakeFiles/Smen.dir/linklibs.rsp
Smen.exe: CMakeFiles/Smen.dir/objects1.rsp
Smen.exe: CMakeFiles/Smen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Smen.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Smen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Smen.dir/build: Smen.exe

.PHONY : CMakeFiles/Smen.dir/build

CMakeFiles/Smen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Smen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Smen.dir/clean

CMakeFiles/Smen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Smen\cmake-build-debug\CMakeFiles\Smen.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Smen.dir/depend

