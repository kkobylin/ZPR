#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color, std::string figure_name) :
        Piece (column, row, color, figure_name){};
    void move(Position, BaseBoard) override;
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
    double getPositionValue() override ;
};
#endif
