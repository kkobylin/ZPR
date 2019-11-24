#ifndef EMPTY
#define EMPTY
#include "Piece.h"

class Empty : public Piece{
public:
    Empty(int column, int row, PieceColor color) :
    Piece (column, row, color){};
};
#endif
