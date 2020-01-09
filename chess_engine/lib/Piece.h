#ifndef PIECE
#define PIECE
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
//#include "Board.h"

class Board;

enum PieceColor {
    BLACK = -1,
    WHITE = 1
};

struct Position{
    int column = -1;
    int row = -1;

    bool operator==(Position pos1){ return pos1.column == column && pos1.row == row;} // override operator to use std::find
    bool operator!=(Position pos1){ return pos1.column != column || pos1.row != row;} // override operator to use std::find
};


const int ROW_MIN = 0;
const int COLUMN_MIN = 0;
const int ROW_MAX = 8;
const int COLUMN_MAX = 8;


class Piece{
private:
    std::string           figureName; // name of figure to transfer to frontend
    PieceColor            color = BLACK; // color of figure
    Position              position; // position on board, cosists od column and row
    int                   column; // vertical position of figure
    int                   row; // horizontal position of figure
    bool                  killed; // is figure killed
    bool                  occupied = true; // is square occupied
    bool                  moved = false; // was figure moved, used to castle and en passant pawn move
    std::vector<Position> moves; // vector of possible moves


public:
    Piece(int, int, PieceColor);
    Piece(int, int, bool occupied);
    Piece(int, int, bool occupied, std::string);
    Piece(int, int, PieceColor, std::string);

    Piece(Position, PieceColor);
    Piece(Position, bool occupied);
    Piece(Position, PieceColor, std::string){}; // todo

    void setKilled(bool); // set figure killed
    void setColor(PieceColor); // set color of figure
    void setRow(int); // set figure row
    void setColumn(int); // set figure column
    void setPosition(Position); // set figure position (column and row)
    void setMoved(); // set if piece moved
    void setOccupied(bool); // set square occupied
    void setMoves(std::vector<Position>); // set possible moves
    void setFigureName(std::string); // set figure name
    virtual void move(Position, Board) = 0; // move figure
    virtual std::vector<Position> getPossibleMoves() = 0; // get vector of possible moves

    PieceColor            getColor(); // get color of figure
    int                   getColumn(); // get column of figure
    int                   getRow(); // get row of piece
    Position              getPosition(); // get position of piece (column and row)
    bool                  isKilled(); // set figure killed
    bool                  getMoved(); // set figure moved
    bool                  getOccupied(); // is square occupied

    std::string           getFigureName(); // get figure name

    friend std::ostream & operator<<(std::ostream &out, const Piece &c){return out << c.column << c.row << c.color << c.figureName << std::endl;}; // output position and figure name
};
#endif