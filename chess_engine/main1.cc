#include "lib/BaseBoard.h"
#include <iostream>
#include "lib/Piece.h"
#include "lib/Bishop.h"
#include "lib/Rook.h"
#include "lib/Knight.h"
#include "lib/King.h"
#include "lib/Queen.h"
#include "lib/Pawn.h"
#include "Connector.h"


int main(void){
    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();
    Connector::ifMovePossible("a3", "a2");
    Connector::opponentMove();

    Connector::ifMovePossible("c3", "c2");
    Connector::opponentMove();

    Connector::ifMovePossible("e3", "e2");
    Connector::opponentMove();

    Connector::ifMovePossible("g3", "g2");
    Connector::opponentMove();

    Connector::ifMovePossible("b4", "b2");
    Connector::opponentMove();

    Connector::ifMovePossible("d4", "d2");
    Connector::opponentMove();

    Connector::ifMovePossible("f4", "f2");
    Connector::opponentMove();
    board[1][1]->getPiece()->getPossibleMoves(boardInstance);
    std::vector<Position> possiblePositions = board[1][1]->getPiece()->getMoves();
    for(Position p : possiblePositions){
        std::cout << p.column << p.row;
    }
}

