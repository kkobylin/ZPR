//
// Created by krzysiek on 01.12.2019.
//

#include "Connector.h"
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "lib/Board.h"
#include <memory>

// todo zmienic board zeby mialo wiersze x kolumny
bool const Connector::ifMovePossible(std::string dest, std::string src){
    std::shared_ptr<Board> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();

    int src_col = src[0] - 'a';
    int src_row = (src[1] - '0') - 1;
    int dest_col = dest[0] - 'a';
    int dest_row = (dest[1] - '0') - 1;

    board[src_col][src_row]->setPossibleMove(boardInstance);
    std::vector<Position> possiblePositions = board[src_col][src_row]->getMoves();
    for(Position p : possiblePositions){
        if(p.column == dest_col && p.row == dest_row)
            board[dest_col][dest_row] = board[src_col][src_row];
            board[src_col][src_row] = new std::shared_ptr<Empty> {new Empty(src_col, src_row, false, "NN")};
            return true;
    }

    return false;
}


BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible)
                ;
        }