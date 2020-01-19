project(chess_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(tests
        FigureLogicTest.cc
        ../lib/BaseBoard.h
        ../lib/Bishop.h
        ../lib/Board.h
        ../lib/King.h
        ../lib/Knight.h
        ../lib/Pawn.h
        ../lib/Piece.h
        ../lib/Queen.h
        ../lib/Rook.h
        ../lib/Square.h
        ../BaseBoard.cc
        ../Bishop.cc
        ../Board.cc
        ../Connector.cc
        ../lib/Connector.h
        ../King.cc
        ../Knight.cc
        ../Pawn.cc
        ../Piece.cc
        ../Queen.cc
        ../Rook.cc
        ../Square.cc
        ../AI/AIClass.cc
        ../AI/AIClass.h
        ../AI/PositionValue.h
        ../AI/PositionValue.cc
        ../exceptions/WrongArgException.h
        FigureLogicTest.cc
        EndOfGameTest.cc
        ExceptionTest.cc)

set(PYTHON_INCLUDE "/usr/include/python3.6")
target_link_libraries(tests python3.6m boost_python3 boost_unit_test_framework )
find_package(Boost 1.65 REQUIRED COMPONENTS python3)


if(Boost_FOUND)
    message(STATUS "It works!")
    include_directories(${Boost_INCLUDE_DIRS}, ${PYTHON_INCLUDE})
    link_directories(${Boost_Linker})
endif()

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
