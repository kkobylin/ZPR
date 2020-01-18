#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:

    Queen(const int column,const int row,const PieceColor color,const std::string figure_name) :
        Piece (column, row, color, figure_name){};

    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>,const bool) override;
    double getPositionValue() const override ;
};
#endif
