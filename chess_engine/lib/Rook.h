#ifndef ROOK
#define ROOK
#include "Piece.h"
#include "Board.h"


class Rook : public Piece{
public:
    Rook(const int column,const int row,const PieceColor color,const std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>,const bool) override;
    double getPositionValue() const override ;
};
#endif
