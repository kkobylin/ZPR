#ifndef ROOK
#define ROOK
#include "Piece.h"
#include "Board.h"


class Rook : public Piece{
private:
    bool moved = false;

public:
    Rook(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    void move(Position, Board) override;
    
    bool getMoved();
    void setMoved(bool);
};
#endif
