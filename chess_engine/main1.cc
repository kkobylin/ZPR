#include "lib/BaseBoard.h"
#include <iostream>

int main(void){
    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            std::cout << boardInstance->getBoardString()[column][row] << " " << std::endl;
            if (row == 7) std::cout << std::endl;
        }
    }
    std::shared_ptr<BaseBoard> board_temp (new BaseBoard(boardInstance->getBoardString()));
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            std::cout << board_temp->getBoardString()[column][row] << " " << std::endl;
            if (row == 7){
                std::cout << std::endl;
            }
        }
    }
    board[1][1]->getPiece()->getPossibleMoves(boardInstance);
    std::vector<Position> possiblePositions = board[1][1]->getPiece()->getMoves();
    for(Position p : possiblePositions){
        std::cout << p.column << p.row;
    }
}

