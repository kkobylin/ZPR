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
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
    void move(Position);
    
    double getPositionValue() override ;
};
#endif
