//
// Created by krzysiek on 01.12.2019.
//

#include "Connector.h"
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "lib/Board.h"
#include <memory>
#include <string>

bool const Connector::ifMovePossible(std::string dest, std::string src){

    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();

    /* Convert columns from A to H to 0-7*/
    // 97 - value of 'a' in ASCII table
    int src_col = static_cast<int>(src[0]) - 97;
    int dest_col = static_cast<int>(dest[0]) - 97;

    /* Convert rows from 1 to 8 to 0-7*/
    int src_row = std::stoi(src.substr(1,1));
    src_row --;
    int dest_row = std::stoi(dest.substr(1,1));
    dest_row --;

    std::vector<Position> possiblePositions = board[src_col][src_row]->getPiece()->getPossibleMoves(boardInstance);
    for(Position p : possiblePositions){
        if(p.column == dest_col && p.row == dest_row){
            //update board
                //update destination Square
            board[dest_col][dest_row]->setPiece(board[src_col][src_row]->getPiece());
            board[dest_col][dest_row]->setOccupied(true);
            board[dest_col][dest_row]->getPiece()->setPosition(p); // aktualizacja pozycji figury
            board[dest_col][dest_row]->getPiece()->setMoved();

                //update source Square
            board[src_col][src_row]->setPiece(std::shared_ptr<Piece>{nullptr});
            board[src_col][src_row]->setOccupied(false);


            std::cout << "destination place of figure: " << *(board[dest_col][dest_row]->getPiece()) << std::endl; //test
            return true;

        }
        
    }

    return false;

}

std::string const Connector::checkForWin() {
    /* none draw win lose*/
    //todo cpp function to check win
    return "none";
}

std::string const Connector::opponentMove(){
        /* Format e2-e4 */
    return "h8-h8";
}

BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible);
                def("checkForWin", Connector::checkForWin);
                def("opponentMove", Connector::opponentMove);
        }