#ifndef KNIGHT
#define KNIGHT
#include "Piece.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color) : 
    Piece(column, row, color){};

};
#endif
