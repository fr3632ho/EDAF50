# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build

# Include any dependencies generated for this target.
include testlib/CMakeFiles/TestLib.dir/depend.make

# Include the progress variables for this target.
include testlib/CMakeFiles/TestLib.dir/progress.make

# Include the compile flags for this target's objects.
include testlib/CMakeFiles/TestLib.dir/flags.make

testlib/CMakeFiles/TestLib.dir/foo.cc.o: testlib/CMakeFiles/TestLib.dir/flags.make
testlib/CMakeFiles/TestLib.dir/foo.cc.o: ../testlib/foo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object testlib/CMakeFiles/TestLib.dir/foo.cc.o"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestLib.dir/foo.cc.o -c /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/foo.cc

testlib/CMakeFiles/TestLib.dir/foo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestLib.dir/foo.cc.i"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/foo.cc > CMakeFiles/TestLib.dir/foo.cc.i

testlib/CMakeFiles/TestLib.dir/foo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestLib.dir/foo.cc.s"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/foo.cc -o CMakeFiles/TestLib.dir/foo.cc.s

testlib/CMakeFiles/TestLib.dir/bar.cc.o: testlib/CMakeFiles/TestLib.dir/flags.make
testlib/CMakeFiles/TestLib.dir/bar.cc.o: ../testlib/bar.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object testlib/CMakeFiles/TestLib.dir/bar.cc.o"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestLib.dir/bar.cc.o -c /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/bar.cc

testlib/CMakeFiles/TestLib.dir/bar.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestLib.dir/bar.cc.i"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/bar.cc > CMakeFiles/TestLib.dir/bar.cc.i

testlib/CMakeFiles/TestLib.dir/bar.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestLib.dir/bar.cc.s"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib/bar.cc -o CMakeFiles/TestLib.dir/bar.cc.s

# Object files for target TestLib
TestLib_OBJECTS = \
"CMakeFiles/TestLib.dir/foo.cc.o" \
"CMakeFiles/TestLib.dir/bar.cc.o"

# External object files for target TestLib
TestLib_EXTERNAL_OBJECTS =

testlib/libTestLib.a: testlib/CMakeFiles/TestLib.dir/foo.cc.o
testlib/libTestLib.a: testlib/CMakeFiles/TestLib.dir/bar.cc.o
testlib/libTestLib.a: testlib/CMakeFiles/TestLib.dir/build.make
testlib/libTestLib.a: testlib/CMakeFiles/TestLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libTestLib.a"
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && $(CMAKE_COMMAND) -P CMakeFiles/TestLib.dir/cmake_clean_target.cmake
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
testlib/CMakeFiles/TestLib.dir/build: testlib/libTestLib.a

.PHONY : testlib/CMakeFiles/TestLib.dir/build

testlib/CMakeFiles/TestLib.dir/clean:
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib && $(CMAKE_COMMAND) -P CMakeFiles/TestLib.dir/cmake_clean.cmake
.PHONY : testlib/CMakeFiles/TestLib.dir/clean

testlib/CMakeFiles/TestLib.dir/depend:
	cd /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/testlib /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib /h/d6/z/fr3632ho-s/C++/EDAF50/lab1/cmake-example/build/testlib/CMakeFiles/TestLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testlib/CMakeFiles/TestLib.dir/depend
