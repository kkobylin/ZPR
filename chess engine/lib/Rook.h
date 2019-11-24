#ifndef ROOK
#define ROOK
#include "Piece.h"


class Rook : public Piece{
private:
    bool moved = false;

public:
    Rook(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    
    bool getMoved();
    void setMoved(bool);
};
#endif
