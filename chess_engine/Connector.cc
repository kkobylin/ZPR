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

    int src_col = src[0] - 'a'; std::cout << "src_col" << src_col << std::endl; //test
    int src_row = (src[1] - '0') - 1; std::cout << "src_row" << src_row << std::endl; //test
    int dest_col = dest[0] - 'a'; std::cout << "dest_col" << dest_col << std::endl; //test
    int dest_row = (dest[1] - '0') - 1; std::cout << "dest_row" << dest_row << std::endl; //test
    std::cout << "source place of figure: " << board[src_col][src_row]->getPiece() << std::endl; //test

    board[src_col][src_row]->getPiece()->setPossibleMove(boardInstance);
    std::vector<Position> possiblePositions = board[src_col][src_row]->getPiece()->getMoves();

    for(Position p : possiblePositions){
        if(p.column == dest_col && p.row == dest_row){
            //update board
                //update destination Square
            board[dest_col][dest_row]->setPiece(board[src_col][src_row]->getPiece());
            board[dest_col][dest_row]->setOccupied(true);
            board[dest_col][dest_row]->getPiece()->setPosition(p); // aktualizacja pozycji figury
            if(board[dest_col][dest_row]->getPiece()->getFigureName() == "P"){
                board[dest_col][dest_row]->getPiece()->setMoved();
            }

                //update source Square
            board[src_col][src_row]->setPiece(std::shared_ptr<Piece>{nullptr});
            board[src_col][src_row]->setOccupied(false);


            std::cout << "destination place of figure: " << *(board[dest_col][dest_row]->getPiece()) << std::endl; //test
            return true;

        }
        
    }

    return false;
}


BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible)
                ;
        }