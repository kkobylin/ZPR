cmake_minimum_required(VERSION 3.15)
project(ZPR)

set(CMAKE_CXX_STANDARD 14)

include_directories("chess engine")
include_directories("chess engine/lib")

add_executable(ZPR
        "chess engine/lib/Bishop.h"
        "chess engine/lib/Board.h"
        "chess engine/lib/Empty_square.h"
        "chess engine/lib/King.h"
        "chess engine/lib/Knight.h"
        "chess engine/lib/Pawn.h"
        "chess engine/lib/Piece.h"
        "chess engine/lib/Queen.h"
        "chess engine/lib/Rook.h"
        "chess engine/lib/Square.h"
        "chess engine/Bishop.cc"
        "chess engine/Board.cc"
        "chess engine/Connector.cpp"
        "chess engine/Connector.h"
        "chess engine/Empty_square.cc"
        "chess engine/King.cc"
        "chess engine/Knight.cc"
        "chess engine/main.cc"
        "chess engine/main.cpp"
        "chess engine/Pawn.cc"
        "chess engine/Piece.cc"
        "chess engine/Queen.cc"
        "chess engine/Rook.cc"
        "chess engine/Square.cc")
