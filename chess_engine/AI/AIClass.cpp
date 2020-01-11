//
// Created by Krzysiek on 29/11/2019.
//
#include "AIClass.h"

double AIClass::evaluateBoard(board_type board) {

    double result = 0;

    for(auto column : board)
        for(auto square : column){
            if(square->getOccupied())
                result += square->getPiece->getPositionValue();
        }

    return result;
}

MovePacket AIClass::MiniMaxRoot(int depth, PieceColor turn){
    auto boardObj = Board::getInstance();
    board_type board = boardObj->getBoard();
    double maxValue = 0;

    for(auto column : board)
        for(auto square : column){
            if(square->getOccupied() && sq)
                result += square->getPiece->getPositionValue();
        }

}