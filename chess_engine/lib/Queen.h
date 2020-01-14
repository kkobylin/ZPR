#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color, std::string figureName) :
        Piece (column, row, color, figureName){};
<<<<<<< HEAD
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
=======
    void move(Position, BaseBoard) override;
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
>>>>>>> master
    double getPositionValue() override ;
};
#endif
