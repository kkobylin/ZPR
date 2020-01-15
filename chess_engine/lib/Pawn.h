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
    Pawn(int column, int row, PieceColor color, std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
    void move(Position);
    void move(Position, BaseBoard) override;
    double getPositionValue() override ;
};
#endif
