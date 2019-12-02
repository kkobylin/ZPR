#ifndef QUEEN
#define QUEEN
#include "Piece.h"
#include "Board.h"


class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color, std::string figureName) :
    Piece (column, row, color, figureName){};
    void move(Position, Board) override;
    void setPossibleMove(std::shared_ptr<Board>) override;
};
#endif
