#ifndef BISHOP
#define BISHOP
#include "Piece.h"
#include "Board.h"

class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color, std::string figureName) :
        Piece (column, row, color, figureName){};
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
    double getPositionValue() override ;
};
#endif
