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
    Pawn(const int column,const int row,const PieceColor color,const std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>,const bool) override;
    
    double getPositionValue() const override ;
};
#endif
