#include "Piece.h"
#include <vector>


enum Column {
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8
};

class Square{
private:
    Piece piece;
    int   column;
    int   row;

public:
    Piece(int column, int row, Piece piece);

    void setPiece();
    void setColumn(int column);
    void setRow(int row);

    Piece getPiece();
    int   getRow();
    int   getColumn();
};


class Board{
private:
    std::vector <std::vector <Square>> board;
    int x;
    int y;
public:
    Board();
    void updateSquare(int column, int row, Piece piece);


};
