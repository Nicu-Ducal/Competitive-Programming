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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Padure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Padure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Padure.dir/flags.make

CMakeFiles/Padure.dir/main.cpp.obj: CMakeFiles/Padure.dir/flags.make
CMakeFiles/Padure.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Padure.dir/main.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Padure.dir\main.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\main.cpp"

CMakeFiles/Padure.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Padure.dir/main.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\main.cpp" > CMakeFiles\Padure.dir\main.cpp.i

CMakeFiles/Padure.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Padure.dir/main.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\main.cpp" -o CMakeFiles\Padure.dir\main.cpp.s

# Object files for target Padure
Padure_OBJECTS = \
"CMakeFiles/Padure.dir/main.cpp.obj"

# External object files for target Padure
Padure_EXTERNAL_OBJECTS =

Padure.exe: CMakeFiles/Padure.dir/main.cpp.obj
Padure.exe: CMakeFiles/Padure.dir/build.make
Padure.exe: CMakeFiles/Padure.dir/linklibs.rsp
Padure.exe: CMakeFiles/Padure.dir/objects1.rsp
Padure.exe: CMakeFiles/Padure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Padure.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Padure.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Padure.dir/build: Padure.exe

.PHONY : CMakeFiles/Padure.dir/build

CMakeFiles/Padure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Padure.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Padure.dir/clean

CMakeFiles/Padure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Arhiva probleme\Padure\cmake-build-debug\CMakeFiles\Padure.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Padure.dir/depend

