# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\use\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\use\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\clion_project\TSshangji

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\clion_project\TSshangji\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TSshangji.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TSshangji.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TSshangji.dir/flags.make

CMakeFiles/TSshangji.dir/DP/P1220.cpp.obj: CMakeFiles/TSshangji.dir/flags.make
CMakeFiles/TSshangji.dir/DP/P1220.cpp.obj: ../DP/P1220.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\clion_project\TSshangji\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TSshangji.dir/DP/P1220.cpp.obj"
	D:\mingw8.1.0\i_am_here\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TSshangji.dir\DP\P1220.cpp.obj -c E:\clion_project\TSshangji\DP\P1220.cpp

CMakeFiles/TSshangji.dir/DP/P1220.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TSshangji.dir/DP/P1220.cpp.i"
	D:\mingw8.1.0\i_am_here\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\clion_project\TSshangji\DP\P1220.cpp > CMakeFiles\TSshangji.dir\DP\P1220.cpp.i

CMakeFiles/TSshangji.dir/DP/P1220.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TSshangji.dir/DP/P1220.cpp.s"
	D:\mingw8.1.0\i_am_here\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\clion_project\TSshangji\DP\P1220.cpp -o CMakeFiles\TSshangji.dir\DP\P1220.cpp.s

# Object files for target TSshangji
TSshangji_OBJECTS = \
"CMakeFiles/TSshangji.dir/DP/P1220.cpp.obj"

# External object files for target TSshangji
TSshangji_EXTERNAL_OBJECTS =

TSshangji.exe: CMakeFiles/TSshangji.dir/DP/P1220.cpp.obj
TSshangji.exe: CMakeFiles/TSshangji.dir/build.make
TSshangji.exe: CMakeFiles/TSshangji.dir/linklibs.rsp
TSshangji.exe: CMakeFiles/TSshangji.dir/objects1.rsp
TSshangji.exe: CMakeFiles/TSshangji.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\clion_project\TSshangji\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TSshangji.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TSshangji.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TSshangji.dir/build: TSshangji.exe

.PHONY : CMakeFiles/TSshangji.dir/build

CMakeFiles/TSshangji.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TSshangji.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TSshangji.dir/clean

CMakeFiles/TSshangji.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\clion_project\TSshangji E:\clion_project\TSshangji E:\clion_project\TSshangji\cmake-build-debug E:\clion_project\TSshangji\cmake-build-debug E:\clion_project\TSshangji\cmake-build-debug\CMakeFiles\TSshangji.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TSshangji.dir/depend

