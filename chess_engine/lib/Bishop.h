#ifndef BISHOP
#define BISHOP
#include "Piece.h"
#include "Board.h"



class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color, std::string figureName) :
    Piece (column, row, color, figureName){};
    void move(Position, Board) override;
    std::vector<Position> getPossibleMove() override;
};
#endif
