#ifndef PIECE
#define PIECE
#include <string>
#include <vector>
#include <algorithm>
#include <string>
//#include "Board.h"

class Board;

enum PieceColor {
    BLACK = -1,
    WHITE = 1
};

struct Position{
    int column = -1;
    int row = -1;

    bool operator==(Position pos1){
        return pos1.column == column &&
               pos1.row    == row;
    }
    bool operator!=(Position pos1){
        return pos1.column != column ||
               pos1.row    != row;
    }
};


const int ROW_MIN = 0;
const int COLUMN_MIN = 0;
const int ROW_MAX = 8;
const int COLUMN_MAX = 8;


class Piece{
private:
    PieceColor       color;
    Position         position;
    int              column;
    int              row;
    bool             killed;
    bool             occupied = true;
    bool             moved = false;
    std::vector<Position> moves;


public:
    Piece(int, int, PieceColor);
    Piece(int, int, bool occupied);

    Piece(Position, PieceColor);
    Piece(Position, bool occupied);
    //virtual Piece* clone() const = 0;

    //bool    color(); cos nie tak
    void setKilled(bool);
    void setColor(PieceColor);
    void setRow(int);
    void setColumn(int);
    void setPosition(Position);
    //void move(Position); zaimplementować
    void setMoved();
    void setOccupied(bool);
    void setMoves(std::vector<Position>);
    virtual void move(Position, Board) = 0;

    PieceColor            getColor();
    int                   getColumn();
    int                   getRow();
    Position              getPosition();
    bool                  isKilled();
    bool                  getMoved();
    bool                  getOccupied();
    std::vector<Position> getMoves();
    //virtual std::vector<int> getPossibleMove(Board); zaimplementować w 
    //virtual void             updatePossibleNextMove(); klasach

};
#endif