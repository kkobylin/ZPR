#ifndef KING
#define KING
#include "Piece.h"


class King : public Piece{
private:
    bool moved = false;
    bool castled = false;
    bool checked = false;

public:
    King(int column, int row, PieceColor color) :
    Piece (column, row, color){};
    
    bool getMoved();
    bool getCastled();
    bool getChecked();

    void setMoved(bool moved);
    void setCastled(bool castled);
    void setChecked(bool checked);
};
#endif
