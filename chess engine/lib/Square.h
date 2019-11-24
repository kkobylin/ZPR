#ifndef SQUARE
#define SQUARE
#include "Piece.h"

class Square{
private:
    Piece * piece{};
    int   column;
    int   row;

public:
    Square(Piece *);
    void setPiece(Piece *);
    void setColumn(int);
    void setRow(int);

    Piece * getPiece();
    int   getRow();
    int   getColumn();
};
#endif
