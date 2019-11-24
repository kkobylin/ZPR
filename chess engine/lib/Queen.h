#ifndef QUEEN
#define QUEEN
#include "Piece.h"


class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color) :
    Piece (column, row, color){};
};
#endif
