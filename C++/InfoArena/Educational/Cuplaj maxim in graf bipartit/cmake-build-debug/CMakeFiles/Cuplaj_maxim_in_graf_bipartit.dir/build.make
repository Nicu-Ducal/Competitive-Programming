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
include CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/flags.make

CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.obj: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/flags.make
CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\main.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\main.cpp"

CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\main.cpp" > CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\main.cpp.i

CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\main.cpp" -o CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\main.cpp.s

# Object files for target Cuplaj_maxim_in_graf_bipartit
Cuplaj_maxim_in_graf_bipartit_OBJECTS = \
"CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.obj"

# External object files for target Cuplaj_maxim_in_graf_bipartit
Cuplaj_maxim_in_graf_bipartit_EXTERNAL_OBJECTS =

Cuplaj_maxim_in_graf_bipartit.exe: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/main.cpp.obj
Cuplaj_maxim_in_graf_bipartit.exe: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/build.make
Cuplaj_maxim_in_graf_bipartit.exe: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/linklibs.rsp
Cuplaj_maxim_in_graf_bipartit.exe: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/objects1.rsp
Cuplaj_maxim_in_graf_bipartit.exe: CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cuplaj_maxim_in_graf_bipartit.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/build: Cuplaj_maxim_in_graf_bipartit.exe

.PHONY : CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/build

CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/clean

CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\InfoArena\Educational\Cuplaj maxim in graf bipartit\cmake-build-debug\CMakeFiles\Cuplaj_maxim_in_graf_bipartit.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Cuplaj_maxim_in_graf_bipartit.dir/depend

