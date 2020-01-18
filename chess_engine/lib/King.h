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
    King(const int column,const int row,const PieceColor color,const std::string figure_name) :
        Piece (column, row, color, figure_name){};
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>,const bool) override;

    double getPositionValue() const override ;

    //todo usunac
    bool getMoved() const;
    bool getCastled() const;
    bool getChecked() const;
    void setCastled(const bool castled);
    void setChecked(const bool checked);
};
#endif
