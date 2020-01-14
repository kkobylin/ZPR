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

    if(dest == "offboard")
        return false;

    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();

    /* Convert columns from A to H to 0-7*/
    int src_col;
    int dest_col;
    switch (src[0]){
        case 'a':
            src_col = 0;
            break;
        case 'b':
            src_col = 1;
            break;
        case 'c':
            src_col = 2;
            break;
        case 'd':
            src_col = 3;
            break;
        case 'e':
            src_col = 4;
            break;
        case 'f':
            src_col = 5;
            break;
        case 'g':
            src_col = 6;
            break;
        case 'h':
            src_col = 7;
            break;
        default:
            return false;
    }

    switch (dest[0]){
        case 'a':
            dest_col = 0;
            break;
        case 'b':
            dest_col = 1;
            break;
        case 'c':
            dest_col = 2;
            break;
        case 'd':
            dest_col = 3;
            break;
        case 'e':
            dest_col = 4;
            break;
        case 'f':
            dest_col = 5;
            break;
        case 'g':
            dest_col = 6;
            break;
        case 'h':
            dest_col = 7;
            break;
        default:
            return false;
    }

    /* Convert rows from 1 to 8 to 0-7*/
    int src_row = std::stoi(src.substr(1,1));
    src_row --;
    int dest_row = std::stoi(dest.substr(1,1));
    dest_row --;
    //boardInstance->printBoardCout();
    std::vector<Position> possiblePositions = board[src_col][src_row]->getPiece()->getPossibleMoves(boardInstance);

    for(Position p : possiblePositions){
        if(p.column == dest_col && p.row == dest_row){
            boardInstance->updateBoard(dest_col,dest_row,src_col,src_row);
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
    auto board = Board::getInstance();
    std::shared_ptr<BaseBoard> minMaxBoard(new BaseBoard(board->toString()));

    MovePacket movePacket = AIClass::MiniMaxRoot(2, BLACK, minMaxBoard, BLACK);
    board->updateBoard(movePacket.dest_col, movePacket.dest_row, movePacket.src_col, movePacket.src_row);

    std::string chessColumnConvert[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

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