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
CMAKE_SOURCE_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/counting_rooms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/counting_rooms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/counting_rooms.dir/flags.make

CMakeFiles/counting_rooms.dir/counting_rooms.cpp.obj: CMakeFiles/counting_rooms.dir/flags.make
CMakeFiles/counting_rooms.dir/counting_rooms.cpp.obj: ../counting_rooms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/counting_rooms.dir/counting_rooms.cpp.obj"
	C:\Programs\msys2-mingw64-9\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\counting_rooms.dir\counting_rooms.cpp.obj -c "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\counting_rooms.cpp"

CMakeFiles/counting_rooms.dir/counting_rooms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/counting_rooms.dir/counting_rooms.cpp.i"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\counting_rooms.cpp" > CMakeFiles\counting_rooms.dir\counting_rooms.cpp.i

CMakeFiles/counting_rooms.dir/counting_rooms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/counting_rooms.dir/counting_rooms.cpp.s"
	C:\Programs\msys2-mingw64-9\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\counting_rooms.cpp" -o CMakeFiles\counting_rooms.dir\counting_rooms.cpp.s

# Object files for target counting_rooms
counting_rooms_OBJECTS = \
"CMakeFiles/counting_rooms.dir/counting_rooms.cpp.obj"

# External object files for target counting_rooms
counting_rooms_EXTERNAL_OBJECTS =

counting_rooms.exe: CMakeFiles/counting_rooms.dir/counting_rooms.cpp.obj
counting_rooms.exe: CMakeFiles/counting_rooms.dir/build.make
counting_rooms.exe: CMakeFiles/counting_rooms.dir/linklibs.rsp
counting_rooms.exe: CMakeFiles/counting_rooms.dir/objects1.rsp
counting_rooms.exe: CMakeFiles/counting_rooms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable counting_rooms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\counting_rooms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/counting_rooms.dir/build: counting_rooms.exe

.PHONY : CMakeFiles/counting_rooms.dir/build

CMakeFiles/counting_rooms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\counting_rooms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/counting_rooms.dir/clean

CMakeFiles/counting_rooms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES" "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES" "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug" "C:\Users\Nicu\Desktop\Competitive Programming\C++\CSES\cmake-build-debug\CMakeFiles\counting_rooms.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/counting_rooms.dir/depend

