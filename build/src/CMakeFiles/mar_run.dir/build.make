# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gabeiglio/Desktop/Developer/Mar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gabeiglio/Desktop/Developer/Mar/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mar_run.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mar_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mar_run.dir/flags.make

src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o: ../src/Evaluator/ASTVisualizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/Evaluator/ASTVisualizer.cpp

src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/Evaluator/ASTVisualizer.cpp > CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.i

src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/Evaluator/ASTVisualizer.cpp -o CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.s

src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o: ../src/Lexer/Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Lexer.cpp

src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Lexer.cpp > CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.i

src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Lexer.cpp -o CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.s

src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.o: ../src/Parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/Parser/Parser.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Parser.cpp

src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/Parser/Parser.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Parser.cpp > CMakeFiles/mar_run.dir/Parser/Parser.cpp.i

src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/Parser/Parser.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Parser.cpp -o CMakeFiles/mar_run.dir/Parser/Parser.cpp.s

src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o: ../src/Sema/SemanticAnalyzer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SemanticAnalyzer.cpp

src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SemanticAnalyzer.cpp > CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.i

src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SemanticAnalyzer.cpp -o CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.s

src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o: ../src/Sema/SymbolTable/SymbolTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SymbolTable/SymbolTable.cpp

src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SymbolTable/SymbolTable.cpp > CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.i

src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/Sema/SymbolTable/SymbolTable.cpp -o CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.s

src/CMakeFiles/mar_run.dir/main.cpp.o: src/CMakeFiles/mar_run.dir/flags.make
src/CMakeFiles/mar_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/mar_run.dir/main.cpp.o"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mar_run.dir/main.cpp.o -c /Users/gabeiglio/Desktop/Developer/Mar/src/main.cpp

src/CMakeFiles/mar_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mar_run.dir/main.cpp.i"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gabeiglio/Desktop/Developer/Mar/src/main.cpp > CMakeFiles/mar_run.dir/main.cpp.i

src/CMakeFiles/mar_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mar_run.dir/main.cpp.s"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gabeiglio/Desktop/Developer/Mar/src/main.cpp -o CMakeFiles/mar_run.dir/main.cpp.s

# Object files for target mar_run
mar_run_OBJECTS = \
"CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o" \
"CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o" \
"CMakeFiles/mar_run.dir/Parser/Parser.cpp.o" \
"CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o" \
"CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o" \
"CMakeFiles/mar_run.dir/main.cpp.o"

# External object files for target mar_run
mar_run_EXTERNAL_OBJECTS =

src/mar_run: src/CMakeFiles/mar_run.dir/Evaluator/ASTVisualizer.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/Lexer/Lexer.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/Parser/Parser.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/Sema/SemanticAnalyzer.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/Sema/SymbolTable/SymbolTable.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/main.cpp.o
src/mar_run: src/CMakeFiles/mar_run.dir/build.make
src/mar_run: src/CMakeFiles/mar_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gabeiglio/Desktop/Developer/Mar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable mar_run"
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mar_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mar_run.dir/build: src/mar_run

.PHONY : src/CMakeFiles/mar_run.dir/build

src/CMakeFiles/mar_run.dir/clean:
	cd /Users/gabeiglio/Desktop/Developer/Mar/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mar_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mar_run.dir/clean

src/CMakeFiles/mar_run.dir/depend:
	cd /Users/gabeiglio/Desktop/Developer/Mar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gabeiglio/Desktop/Developer/Mar /Users/gabeiglio/Desktop/Developer/Mar/src /Users/gabeiglio/Desktop/Developer/Mar/build /Users/gabeiglio/Desktop/Developer/Mar/build/src /Users/gabeiglio/Desktop/Developer/Mar/build/src/CMakeFiles/mar_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mar_run.dir/depend

