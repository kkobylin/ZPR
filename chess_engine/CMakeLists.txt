# cmake_minimum_required(VERSION <specify CMake version here>)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_library(chesslib SHARED
        lib/Bishop.h
        lib/Board.h
        lib/Empty_square.h
        lib/King.h
        lib/Knight.h
        lib/Pawn.h
        lib/Piece.h
        lib/Queen.h
        lib/Rook.h
        lib/Square.h
        Bishop.cc
        Board.cc
        Connector.cc
        Connector.h
        Empty_square.cc
        King.cc
        Knight.cc
        Pawn.cc
        Piece.cc
        Queen.cc
        Rook.cc
        Square.cc
        AI/AIClass.cpp
        AI/AIClass.h
        AI/PositionValue.h AI/PositionValue.cpp)

set(BOOST_ROOT "/home/krzysiek/Documents/ZPR/boost_1_71_0_rc2/boost_1_71_0")
set(BOOSTROOT "/home/krzysiek/Documents/ZPR/boost_1_71_0_rc2/boost_1_71_0")
set(Boost_INCLUDE_DIR "/home/krzysiek/Documents/ZPR/boost_1_71_0_rc2/boost_1_71_0")
set(PYTHON_INCLUDE "/usr/include/python3.6")
set(Boost_Linker "/home/krzysiek/Documents/ZPR/boost_1_71_0_rc2/boost_1_71_0/stage/lib")

target_link_libraries(chesslib python3.6m boost_system boost_python3)

find_package(Boost 1.71.0 REQUIRED COMPONENTS python3)

if(Boost_FOUND)
    message(STATUS "It works!")
    include_directories(${Boost_INCLUDE_DIRS}, ${PYTHON_INCLUDE})
    link_directories(${Boost_Linker})
endif()

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()