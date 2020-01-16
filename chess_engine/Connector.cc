//
// Created by krzysiek on 01.12.2019.
//

#include "Connector.h"
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "lib/Board.h"
#include <memory>
#include <string>
#include "AI/AIClass.h"
#include "lib/BaseBoard.h"

bool const Connector::ifMovePossible(std::string dest, std::string src){

    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();
    auto temp = boardInstance->toString();

    /* Convert columns from A to H to 0-7*/
    // 97 - value of 'a' in ASCII table
    //todo change method of conversion
    int src_col = static_cast<int>(src[0]) - 97;
    int dest_col = static_cast<int>(dest[0]) - 97;

    /* Convert rows from 1 to 8 to 0-7*/
    int src_row = std::stoi(src.substr(1,1));
    src_row --;
    int dest_row = std::stoi(dest.substr(1,1));
    dest_row --;
    boardInstance->printBoardCout();
    std::cout << "White King: " << boardInstance->getKing(WHITE);
    std::cout << "Black King: " << boardInstance->getKing(BLACK);
  
    
    std::vector<Position> possiblePositions = board[src_col][src_row]->getPiece()->getPossibleMoves(boardInstance);

    for(Position p : possiblePositions){
        std::cout << p.column << p.row << std::endl;

        if(p.column == dest_col && p.row == dest_row){
            boardInstance->updateBoard(dest_col,dest_row,src_col,src_row);
                if (boardInstance->isChecking(WHITE,boardInstance)){
                    std::cout << "Szach bialy" << std::endl;
                }
                    
                if (boardInstance->isChecking(BLACK,boardInstance)){
                    std::cout << "Szach czarny" << std::endl;
                }

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
    //return "h8-h8";

    std::string chessColumnConvert[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

    auto board = Board::getInstance();
    std::shared_ptr<BaseBoard> minMaxBoard(new BaseBoard(board->toString()));

    MovePacket movePacket = AIClass::MiniMaxRoot(2, BLACK, minMaxBoard, BLACK);
    if (board->isCheckMate(WHITE,board)){
        std::cout << "mat bialy" << std::endl;
    }
        
    if (board->isCheckMate(BLACK,board)){
        std::cout << "mat czarny" << std::endl;
    }
    board->updateBoard(movePacket.dest_col, movePacket.dest_row, movePacket.src_col, movePacket.src_row);
    if (board->isChecking(WHITE,board)){
        std::cout << "Szach bialy" << std::endl;
    }
        
    if (board->isChecking(BLACK,board)){
        std::cout << "Szach czarny" << std::endl;
    }
    std::string src_row = std::to_string(++movePacket.src_row);
    std::string src_col = chessColumnConvert[movePacket.src_col];
    std::string dest_row = std::to_string(++movePacket.dest_row);
    std::string dest_col = chessColumnConvert[movePacket.dest_col];

    return src_col + src_row + '-' + dest_col + dest_row;
}

BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible);
                def("checkForWin", Connector::checkForWin);
                def("opponentMove", Connector::opponentMove);
        }