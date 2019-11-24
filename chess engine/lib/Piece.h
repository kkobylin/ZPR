#ifndef PIECE
#define PIECE
#include <string>
#include <vector>
//#include "Board.h"

class Board;

enum PieceColor {
    BLACK = 0,
    WHITE = 1
};


const int ROW_MIN = 0;
const int COLUMN_MIN = 0;
const int ROW_MAX = 8;
const int COLUMN_MAX = 8;


class Piece{
private:
    PieceColor       color;
    int              column;
    int              row;
    bool             killed;
    std::vector<int> possible_next_move;


public:
    Piece(int, int, PieceColor);
    //virtual Piece* clone() const = 0;

    //bool    color(); cos nie tak
    void    setKilled(bool);
    void    setColor(PieceColor);
    void    setRow(int);
    void    setColumn(int);
    void    move(int, int);
    void    setMoved();

    PieceColor getColor();
    int        getColumn();
    int        getRow();
    bool       isKilled();
    //virtual std::vector<int> getPossibleNextMove(Board); zaimplementować w 
    //virtual void             updatePossibleNextMove(); klasach

};
#endif