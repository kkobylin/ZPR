#include "Piece.h"

public class Square{
private:
    private Piece piece;
    private int   column;
    private int   row;

public:
    Square(Piece);

    void setPiece(Piece);
    void setColumn(int);
    void setRow(int);

    Piece getPiece();
    int   getRow();
    int   getColumn();
};