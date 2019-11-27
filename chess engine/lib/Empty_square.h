#ifndef EMPTY
#define EMPTY
#include "Piece.h"
#include "Board.h"

class Empty : public Piece{
public:
    Empty(int column, int row, bool occupied) :
    Piece (column, row, occupied) {};    
    void move(Position, Board) override;
};
#endif
