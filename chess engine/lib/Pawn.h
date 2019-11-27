#ifndef PAWN
#define PAWN
#include "Piece.h"
#include "Board.h"
#include <algorithm>
#include <iostream>


class Pawn : public Piece{
private:
    bool moved = false;
public:
    Pawn(int column, int row, PieceColor color) :
    Piece (column, row, color){};

    void setPossibleMove(Board);
    void move(Position);
    void move(Position, Board) override;
    
};
#endif
