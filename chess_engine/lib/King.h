#ifndef KING
#define KING
#include "Piece.h"
#include "Board.h"

class King : public Piece{
private:
    bool moved = false;
    bool castled = false;
    bool checked = false;

public:
    King(int column, int row, PieceColor color, std::string figureName) :
        Piece (column, row, color, figureName){};
    void move(Position, BaseBoard) override;
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
    double getPositionValue() override ;

    bool getMoved();
    bool getCastled();
    bool getChecked();

    void setMoved(bool moved);
    void setCastled(bool castled);
    void setChecked(bool checked);
};
#endif
