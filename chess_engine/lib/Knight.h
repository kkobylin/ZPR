#ifndef KNIGHT
#define KNIGHT
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color, std::string figureName) :
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
