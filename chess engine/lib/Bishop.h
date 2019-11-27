#ifndef BISHOP
#define BISHOP
#include "Piece.h"
#include "Board.h"



class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    void move(Position, Board) override;
};
#endif
