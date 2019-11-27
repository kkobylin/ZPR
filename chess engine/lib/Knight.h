#ifndef KNIGHT
#define KNIGHT
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color) : 
    Piece(column, row, color){};
    void move(Position, Board) override;

};
#endif
