#ifndef EMPTY
#define EMPTY
#include "Piece.h"
#include "Board.h"

[[deprecated("Changed inheritance dependencies")]]class Empty : public Piece{
public:
    Empty(int column, int row,bool occupied, std::string figureName) :
    Piece (column, row, occupied, figureName){};
    void move(Position, Board) override;
    void setPossibleMove(std::shared_ptr<Board>) override;
};
#endif
