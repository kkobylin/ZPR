# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/marcin/ZPR/ZPR_11_01_2020/chess_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcin/ZPR/ZPR_11_01_2020/chess_engine

# Include any dependencies generated for this target.
include CMakeFiles/chesslib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chesslib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chesslib.dir/flags.make

CMakeFiles/chesslib.dir/Bishop.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Bishop.o: Bishop.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chesslib.dir/Bishop.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Bishop.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Bishop.cc

CMakeFiles/chesslib.dir/Bishop.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Bishop.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Bishop.cc > CMakeFiles/chesslib.dir/Bishop.i

CMakeFiles/chesslib.dir/Bishop.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Bishop.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Bishop.cc -o CMakeFiles/chesslib.dir/Bishop.s

CMakeFiles/chesslib.dir/Bishop.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Bishop.o.requires

CMakeFiles/chesslib.dir/Bishop.o.provides: CMakeFiles/chesslib.dir/Bishop.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Bishop.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Bishop.o.provides

CMakeFiles/chesslib.dir/Bishop.o.provides.build: CMakeFiles/chesslib.dir/Bishop.o


CMakeFiles/chesslib.dir/Board.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Board.o: Board.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chesslib.dir/Board.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Board.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Board.cc

CMakeFiles/chesslib.dir/Board.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Board.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Board.cc > CMakeFiles/chesslib.dir/Board.i

CMakeFiles/chesslib.dir/Board.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Board.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Board.cc -o CMakeFiles/chesslib.dir/Board.s

CMakeFiles/chesslib.dir/Board.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Board.o.requires

CMakeFiles/chesslib.dir/Board.o.provides: CMakeFiles/chesslib.dir/Board.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Board.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Board.o.provides

CMakeFiles/chesslib.dir/Board.o.provides.build: CMakeFiles/chesslib.dir/Board.o


CMakeFiles/chesslib.dir/Connector.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Connector.o: Connector.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chesslib.dir/Connector.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Connector.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Connector.cc

CMakeFiles/chesslib.dir/Connector.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Connector.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Connector.cc > CMakeFiles/chesslib.dir/Connector.i

CMakeFiles/chesslib.dir/Connector.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Connector.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Connector.cc -o CMakeFiles/chesslib.dir/Connector.s

CMakeFiles/chesslib.dir/Connector.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Connector.o.requires

CMakeFiles/chesslib.dir/Connector.o.provides: CMakeFiles/chesslib.dir/Connector.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Connector.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Connector.o.provides

CMakeFiles/chesslib.dir/Connector.o.provides.build: CMakeFiles/chesslib.dir/Connector.o


CMakeFiles/chesslib.dir/Empty_square.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Empty_square.o: Empty_square.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chesslib.dir/Empty_square.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Empty_square.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Empty_square.cc

CMakeFiles/chesslib.dir/Empty_square.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Empty_square.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Empty_square.cc > CMakeFiles/chesslib.dir/Empty_square.i

CMakeFiles/chesslib.dir/Empty_square.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Empty_square.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Empty_square.cc -o CMakeFiles/chesslib.dir/Empty_square.s

CMakeFiles/chesslib.dir/Empty_square.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Empty_square.o.requires

CMakeFiles/chesslib.dir/Empty_square.o.provides: CMakeFiles/chesslib.dir/Empty_square.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Empty_square.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Empty_square.o.provides

CMakeFiles/chesslib.dir/Empty_square.o.provides.build: CMakeFiles/chesslib.dir/Empty_square.o


CMakeFiles/chesslib.dir/King.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/King.o: King.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chesslib.dir/King.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/King.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/King.cc

CMakeFiles/chesslib.dir/King.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/King.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/King.cc > CMakeFiles/chesslib.dir/King.i

CMakeFiles/chesslib.dir/King.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/King.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/King.cc -o CMakeFiles/chesslib.dir/King.s

CMakeFiles/chesslib.dir/King.o.requires:

.PHONY : CMakeFiles/chesslib.dir/King.o.requires

CMakeFiles/chesslib.dir/King.o.provides: CMakeFiles/chesslib.dir/King.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/King.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/King.o.provides

CMakeFiles/chesslib.dir/King.o.provides.build: CMakeFiles/chesslib.dir/King.o


CMakeFiles/chesslib.dir/Knight.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Knight.o: Knight.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chesslib.dir/Knight.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Knight.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Knight.cc

CMakeFiles/chesslib.dir/Knight.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Knight.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Knight.cc > CMakeFiles/chesslib.dir/Knight.i

CMakeFiles/chesslib.dir/Knight.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Knight.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Knight.cc -o CMakeFiles/chesslib.dir/Knight.s

CMakeFiles/chesslib.dir/Knight.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Knight.o.requires

CMakeFiles/chesslib.dir/Knight.o.provides: CMakeFiles/chesslib.dir/Knight.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Knight.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Knight.o.provides

CMakeFiles/chesslib.dir/Knight.o.provides.build: CMakeFiles/chesslib.dir/Knight.o


CMakeFiles/chesslib.dir/Pawn.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Pawn.o: Pawn.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chesslib.dir/Pawn.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Pawn.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Pawn.cc

CMakeFiles/chesslib.dir/Pawn.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Pawn.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Pawn.cc > CMakeFiles/chesslib.dir/Pawn.i

CMakeFiles/chesslib.dir/Pawn.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Pawn.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Pawn.cc -o CMakeFiles/chesslib.dir/Pawn.s

CMakeFiles/chesslib.dir/Pawn.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Pawn.o.requires

CMakeFiles/chesslib.dir/Pawn.o.provides: CMakeFiles/chesslib.dir/Pawn.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Pawn.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Pawn.o.provides

CMakeFiles/chesslib.dir/Pawn.o.provides.build: CMakeFiles/chesslib.dir/Pawn.o


CMakeFiles/chesslib.dir/Piece.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Piece.o: Piece.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chesslib.dir/Piece.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Piece.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Piece.cc

CMakeFiles/chesslib.dir/Piece.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Piece.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Piece.cc > CMakeFiles/chesslib.dir/Piece.i

CMakeFiles/chesslib.dir/Piece.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Piece.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Piece.cc -o CMakeFiles/chesslib.dir/Piece.s

CMakeFiles/chesslib.dir/Piece.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Piece.o.requires

CMakeFiles/chesslib.dir/Piece.o.provides: CMakeFiles/chesslib.dir/Piece.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Piece.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Piece.o.provides

CMakeFiles/chesslib.dir/Piece.o.provides.build: CMakeFiles/chesslib.dir/Piece.o


CMakeFiles/chesslib.dir/Queen.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Queen.o: Queen.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/chesslib.dir/Queen.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Queen.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Queen.cc

CMakeFiles/chesslib.dir/Queen.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Queen.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Queen.cc > CMakeFiles/chesslib.dir/Queen.i

CMakeFiles/chesslib.dir/Queen.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Queen.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Queen.cc -o CMakeFiles/chesslib.dir/Queen.s

CMakeFiles/chesslib.dir/Queen.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Queen.o.requires

CMakeFiles/chesslib.dir/Queen.o.provides: CMakeFiles/chesslib.dir/Queen.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Queen.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Queen.o.provides

CMakeFiles/chesslib.dir/Queen.o.provides.build: CMakeFiles/chesslib.dir/Queen.o


CMakeFiles/chesslib.dir/Rook.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Rook.o: Rook.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/chesslib.dir/Rook.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Rook.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Rook.cc

CMakeFiles/chesslib.dir/Rook.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Rook.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Rook.cc > CMakeFiles/chesslib.dir/Rook.i

CMakeFiles/chesslib.dir/Rook.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Rook.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Rook.cc -o CMakeFiles/chesslib.dir/Rook.s

CMakeFiles/chesslib.dir/Rook.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Rook.o.requires

CMakeFiles/chesslib.dir/Rook.o.provides: CMakeFiles/chesslib.dir/Rook.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Rook.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Rook.o.provides

CMakeFiles/chesslib.dir/Rook.o.provides.build: CMakeFiles/chesslib.dir/Rook.o


CMakeFiles/chesslib.dir/Square.o: CMakeFiles/chesslib.dir/flags.make
CMakeFiles/chesslib.dir/Square.o: Square.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/chesslib.dir/Square.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chesslib.dir/Square.o -c /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Square.cc

CMakeFiles/chesslib.dir/Square.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chesslib.dir/Square.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Square.cc > CMakeFiles/chesslib.dir/Square.i

CMakeFiles/chesslib.dir/Square.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chesslib.dir/Square.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/Square.cc -o CMakeFiles/chesslib.dir/Square.s

CMakeFiles/chesslib.dir/Square.o.requires:

.PHONY : CMakeFiles/chesslib.dir/Square.o.requires

CMakeFiles/chesslib.dir/Square.o.provides: CMakeFiles/chesslib.dir/Square.o.requires
	$(MAKE) -f CMakeFiles/chesslib.dir/build.make CMakeFiles/chesslib.dir/Square.o.provides.build
.PHONY : CMakeFiles/chesslib.dir/Square.o.provides

CMakeFiles/chesslib.dir/Square.o.provides.build: CMakeFiles/chesslib.dir/Square.o


# Object files for target chesslib
chesslib_OBJECTS = \
"CMakeFiles/chesslib.dir/Bishop.o" \
"CMakeFiles/chesslib.dir/Board.o" \
"CMakeFiles/chesslib.dir/Connector.o" \
"CMakeFiles/chesslib.dir/Empty_square.o" \
"CMakeFiles/chesslib.dir/King.o" \
"CMakeFiles/chesslib.dir/Knight.o" \
"CMakeFiles/chesslib.dir/Pawn.o" \
"CMakeFiles/chesslib.dir/Piece.o" \
"CMakeFiles/chesslib.dir/Queen.o" \
"CMakeFiles/chesslib.dir/Rook.o" \
"CMakeFiles/chesslib.dir/Square.o"

# External object files for target chesslib
chesslib_EXTERNAL_OBJECTS =

libchesslib.so: CMakeFiles/chesslib.dir/Bishop.o
libchesslib.so: CMakeFiles/chesslib.dir/Board.o
libchesslib.so: CMakeFiles/chesslib.dir/Connector.o
libchesslib.so: CMakeFiles/chesslib.dir/Empty_square.o
libchesslib.so: CMakeFiles/chesslib.dir/King.o
libchesslib.so: CMakeFiles/chesslib.dir/Knight.o
libchesslib.so: CMakeFiles/chesslib.dir/Pawn.o
libchesslib.so: CMakeFiles/chesslib.dir/Piece.o
libchesslib.so: CMakeFiles/chesslib.dir/Queen.o
libchesslib.so: CMakeFiles/chesslib.dir/Rook.o
libchesslib.so: CMakeFiles/chesslib.dir/Square.o
libchesslib.so: CMakeFiles/chesslib.dir/build.make
libchesslib.so: CMakeFiles/chesslib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX shared library libchesslib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chesslib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chesslib.dir/build: libchesslib.so

.PHONY : CMakeFiles/chesslib.dir/build

CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Bishop.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Board.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Connector.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Empty_square.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/King.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Knight.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Pawn.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Piece.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Queen.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Rook.o.requires
CMakeFiles/chesslib.dir/requires: CMakeFiles/chesslib.dir/Square.o.requires

.PHONY : CMakeFiles/chesslib.dir/requires

CMakeFiles/chesslib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chesslib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chesslib.dir/clean

CMakeFiles/chesslib.dir/depend:
	cd /home/marcin/ZPR/ZPR_11_01_2020/chess_engine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marcin/ZPR/ZPR_11_01_2020/chess_engine /home/marcin/ZPR/ZPR_11_01_2020/chess_engine /home/marcin/ZPR/ZPR_11_01_2020/chess_engine /home/marcin/ZPR/ZPR_11_01_2020/chess_engine /home/marcin/ZPR/ZPR_11_01_2020/chess_engine/CMakeFiles/chesslib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chesslib.dir/depend

