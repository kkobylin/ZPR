#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"


class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    void move(Position, Board) override;
};
#endif
