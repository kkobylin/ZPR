#ifndef ROOK
#define ROOK
#include "Piece.h"
#include "Board.h"


class Rook : public Piece{
private:
    bool moved = false;

public:
    Rook(int column, int row, PieceColor color, std::string figureName) :
    Piece (column, row, color, figureName){};
<<<<<<< HEAD
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
=======
    void move(Position, BaseBoard) override;
    std::vector<Position> getPossibleMoves(const std::shared_ptr<BaseBoard>, bool) override;
>>>>>>> master
    double getPositionValue() override ;

    bool getMoved();
    void setMoved(bool);
};
#endif
