#ifndef KNIGHT
#define KNIGHT
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color, std::string figureName) :
    Piece (column, row, color, figureName){};
    void move(Position, Board) override;
    void setPossibleMove(std::shared_ptr<Board>) override;

};
#endif
