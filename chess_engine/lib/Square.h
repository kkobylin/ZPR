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
    Square(const std::shared_ptr<Piece>);
    void setPiece(const std::shared_ptr<Piece>);
    void setColumn(const int);
    void setRow(const int);
    void setOccupied(const bool);

    std::shared_ptr<Piece> getPiece() const;
    int   getRow() const;
    int   getColumn() const;
    bool getOccupied() const;

};
#endif
