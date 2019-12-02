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

    board[src[1] -'a'][src[0] - 1]->setPossibleMove(boardInstance);
    std::vector<Position> possiblePositions = board[src[0] -'a'][src[1] - 1]->getMoves();
    for(Position p : possiblePositions){
        if(p.column == dest[0] - 'a' && p.row == dest[1] -1 )
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