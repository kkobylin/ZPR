#ifndef PAWN
#define PAWN
#include "Piece.h"
#include "Board.h"
#include <algorithm>
#include <iostream>


class Pawn : public Piece{
private:
    bool moved = false;
public:
    Pawn(int column, int row, PieceColor color, std::string figureName) :
    Piece (column, row, color, figureName){};

    void setPossibleMove(std::shared_ptr<Board>) override;
    void move(Position);
    void move(Position, Board) override;
    
};
#endif
