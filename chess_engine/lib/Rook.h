#ifndef ROOK
#define ROOK
#include "Piece.h"
#include "Board.h"


class Rook : public Piece{
private:
    bool moved = false;

public:

    Rook(int column, int row, PieceColor color, std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
    double getPositionValue() override ;

    bool getMoved();
    void setMoved(bool);
};
#endif
