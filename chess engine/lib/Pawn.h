#ifndef PAWN
#define PAWN
#include "Piece.h"


class Pawn : public Piece{
private:
    bool moved = false;
public:
    Pawn(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    
    bool isMoved();
};
#endif
