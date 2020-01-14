#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color, std::string figureName) :
        Piece (column, row, color, figureName){};
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
    double getPositionValue() override ;
};
#endif
