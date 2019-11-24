#ifndef BISHOP
#define BISHOP
#include "Piece.h"



class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color) :
    Piece (column, row, color){};
};
#endif
