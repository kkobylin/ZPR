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
    void move(Position, Board) override;
    std::vector<Position> getPossibleMoves() override;
    
    bool getMoved();
    void setMoved(bool);
};
#endif
