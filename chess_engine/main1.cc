#include "lib/BaseBoard.h"
#include <iostream>

int main(void){
    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();
    if (board[1][1]->getOccupied()){
        board[1][1]->getPiece()->getPossibleMoves(boardInstance);
    }
    std::vector<Position> possiblePositions = board[1][1]->getPiece()->getMoves();
    for(Position p : possiblePositions){
        std::cout << p.column << p.row;
    }
}

