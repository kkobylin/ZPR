#include "lib/BaseBoard.h"
#include <iostream>
#include "lib/Piece.h"
#include "lib/Bishop.h"
#include "lib/Rook.h"
#include "lib/Knight.h"
#include "lib/King.h"
#include "lib/Queen.h"
#include "lib/Pawn.h"
#include "lib/Empty_square.h"

int main(void){
    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            if(board[column][row]->getOccupied())
                std::cout << boardInstance->getBoard()[column][row]->getColumn()<< boardInstance->getBoard()[column][row]->getRow() <<boardInstance->getBoard()[column][row]->getPiece()->getColumn() << boardInstance->getBoard()[column][row]->getPiece()->getRow();
            std::cout << boardInstance->getBoardString()[column][row] << " ";
            if (row == 7) std::cout << std::endl;
        }
    }
    std::shared_ptr<BaseBoard> board_temp1 (new BaseBoard(boardInstance->getBoardString()));
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            if(board[column][row]->getOccupied())
                std::cout << board_temp1->getBoard()[column][row]->getColumn()<< board_temp1->getBoard()[column][row]->getRow() << board_temp1->getBoard()[column][row]->getPiece()->getColumn() << board_temp1->getBoard()[column][row]->getPiece()->getRow();
            std::cout << board_temp1->getBoardString()[column][row] << " ";
            if (row == 7){
                std::cout << std::endl;
            }
        }
    }
    std::shared_ptr<BaseBoard> board_temp2 (new BaseBoard(board_temp1->getBoardString()));
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            if(board[column][row]->getOccupied())
                std::cout << board_temp2->getBoard()[column][row]->getColumn()<< board_temp2->getBoard()[column][row]->getRow() << board_temp2->getBoard()[column][row]->getPiece()->getColumn() << board_temp2->getBoard()[column][row]->getPiece()->getRow();
            std::cout << board_temp2->getBoardString()[column][row] << " ";
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

