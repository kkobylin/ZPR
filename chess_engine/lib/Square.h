#ifndef SQUARE
#define SQUARE
#include "Piece.h"
#include <memory>

class Square{
private:
    std::shared_ptr<Piece> piece{};
    int   column;
    int   row;
    bool occupied = false;

public:
    Square(std::shared_ptr<Piece>);
    void setPiece(std::shared_ptr<Piece>);
    void setColumn(int);
    void setRow(int);

    std::shared_ptr<Piece> getPiece();
    int   getRow();
    int   getColumn();

    bool getOccupied();
    void setOccupied(bool);
};
#endif
