# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gonca\OneDrive\Aulas\DA\projDA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project1.dir/flags.make

CMakeFiles/Project1.dir/code/main.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/main.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/main.cpp
CMakeFiles/Project1.dir/code/main.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project1.dir/code/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/main.cpp.obj -MF CMakeFiles\Project1.dir\code\main.cpp.obj.d -o CMakeFiles\Project1.dir\code\main.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\main.cpp

CMakeFiles/Project1.dir/code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\main.cpp > CMakeFiles\Project1.dir\code\main.cpp.i

CMakeFiles/Project1.dir/code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\main.cpp -o CMakeFiles\Project1.dir\code\main.cpp.s

CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/CsvLine.cpp
CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj -MF CMakeFiles\Project1.dir\code\src\CsvLine.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\CsvLine.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvLine.cpp

CMakeFiles/Project1.dir/code/src/CsvLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/CsvLine.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvLine.cpp > CMakeFiles\Project1.dir\code\src\CsvLine.cpp.i

CMakeFiles/Project1.dir/code/src/CsvLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/CsvLine.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvLine.cpp -o CMakeFiles\Project1.dir\code\src\CsvLine.cpp.s

CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/CsvReader.cpp
CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj -MF CMakeFiles\Project1.dir\code\src\CsvReader.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\CsvReader.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvReader.cpp

CMakeFiles/Project1.dir/code/src/CsvReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/CsvReader.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvReader.cpp > CMakeFiles\Project1.dir\code\src\CsvReader.cpp.i

CMakeFiles/Project1.dir/code/src/CsvReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/CsvReader.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\CsvReader.cpp -o CMakeFiles\Project1.dir\code\src\CsvReader.cpp.s

CMakeFiles/Project1.dir/code/src/Station.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/Station.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/Station.cpp
CMakeFiles/Project1.dir/code/src/Station.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project1.dir/code/src/Station.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/Station.cpp.obj -MF CMakeFiles\Project1.dir\code\src\Station.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\Station.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Station.cpp

CMakeFiles/Project1.dir/code/src/Station.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/Station.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Station.cpp > CMakeFiles\Project1.dir\code\src\Station.cpp.i

CMakeFiles/Project1.dir/code/src/Station.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/Station.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Station.cpp -o CMakeFiles\Project1.dir\code\src\Station.cpp.s

CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/NetworkSegment.cpp
CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj -MF CMakeFiles\Project1.dir\code\src\NetworkSegment.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\NetworkSegment.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\NetworkSegment.cpp

CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\NetworkSegment.cpp > CMakeFiles\Project1.dir\code\src\NetworkSegment.cpp.i

CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\NetworkSegment.cpp -o CMakeFiles\Project1.dir\code\src\NetworkSegment.cpp.s

CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/VertexEdge.cpp
CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj -MF CMakeFiles\Project1.dir\code\src\VertexEdge.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\VertexEdge.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\VertexEdge.cpp

CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\VertexEdge.cpp > CMakeFiles\Project1.dir\code\src\VertexEdge.cpp.i

CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\VertexEdge.cpp -o CMakeFiles\Project1.dir\code\src\VertexEdge.cpp.s

CMakeFiles/Project1.dir/code/src/Manager.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/Manager.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/Manager.cpp
CMakeFiles/Project1.dir/code/src/Manager.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project1.dir/code/src/Manager.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/Manager.cpp.obj -MF CMakeFiles\Project1.dir\code\src\Manager.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\Manager.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Manager.cpp

CMakeFiles/Project1.dir/code/src/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/Manager.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Manager.cpp > CMakeFiles\Project1.dir\code\src\Manager.cpp.i

CMakeFiles/Project1.dir/code/src/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/Manager.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Manager.cpp -o CMakeFiles\Project1.dir\code\src\Manager.cpp.s

CMakeFiles/Project1.dir/code/src/Graph.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/Graph.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/Graph.cpp
CMakeFiles/Project1.dir/code/src/Graph.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Project1.dir/code/src/Graph.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/Graph.cpp.obj -MF CMakeFiles\Project1.dir\code\src\Graph.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\Graph.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Graph.cpp

CMakeFiles/Project1.dir/code/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/Graph.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Graph.cpp > CMakeFiles\Project1.dir\code\src\Graph.cpp.i

CMakeFiles/Project1.dir/code/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/Graph.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Graph.cpp -o CMakeFiles\Project1.dir\code\src\Graph.cpp.s

CMakeFiles/Project1.dir/code/src/Design.cpp.obj: CMakeFiles/Project1.dir/flags.make
CMakeFiles/Project1.dir/code/src/Design.cpp.obj: C:/Users/gonca/OneDrive/Aulas/DA/projDA/code/src/Design.cpp
CMakeFiles/Project1.dir/code/src/Design.cpp.obj: CMakeFiles/Project1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Project1.dir/code/src/Design.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project1.dir/code/src/Design.cpp.obj -MF CMakeFiles\Project1.dir\code\src\Design.cpp.obj.d -o CMakeFiles\Project1.dir\code\src\Design.cpp.obj -c C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Design.cpp

CMakeFiles/Project1.dir/code/src/Design.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project1.dir/code/src/Design.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Design.cpp > CMakeFiles\Project1.dir\code\src\Design.cpp.i

CMakeFiles/Project1.dir/code/src/Design.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project1.dir/code/src/Design.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonca\OneDrive\Aulas\DA\projDA\code\src\Design.cpp -o CMakeFiles\Project1.dir\code\src\Design.cpp.s

# Object files for target Project1
Project1_OBJECTS = \
"CMakeFiles/Project1.dir/code/main.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/Station.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/Manager.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/Graph.cpp.obj" \
"CMakeFiles/Project1.dir/code/src/Design.cpp.obj"

# External object files for target Project1
Project1_EXTERNAL_OBJECTS =

Project1.exe: CMakeFiles/Project1.dir/code/main.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/CsvLine.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/CsvReader.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/Station.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/NetworkSegment.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/VertexEdge.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/Manager.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/Graph.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/code/src/Design.cpp.obj
Project1.exe: CMakeFiles/Project1.dir/build.make
Project1.exe: CMakeFiles/Project1.dir/linklibs.rsp
Project1.exe: CMakeFiles/Project1.dir/objects1.rsp
Project1.exe: CMakeFiles/Project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Project1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project1.dir/build: Project1.exe
.PHONY : CMakeFiles/Project1.dir/build

CMakeFiles/Project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project1.dir/clean

CMakeFiles/Project1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gonca\OneDrive\Aulas\DA\projDA C:\Users\gonca\OneDrive\Aulas\DA\projDA C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug C:\Users\gonca\OneDrive\Aulas\DA\projDA\cmake-build-debug\CMakeFiles\Project1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project1.dir/depend
