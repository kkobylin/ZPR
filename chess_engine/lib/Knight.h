#ifndef KNIGHT
#define KNIGHT
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color, std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;

    double getPositionValue() override ;
};
#endif
