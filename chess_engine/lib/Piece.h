#ifndef PIECE
#define PIECE
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>

class BaseBoard;

enum PieceColor {
    BLACK = -1,
    WHITE = 1
};

struct Position{
    int column = -1;
    int row = -1;

    bool operator==(const Position pos1){ return pos1.column == column && pos1.row == row;} // override operator to use std::find
    bool operator!=(const Position pos1){ return pos1.column != column || pos1.row != row;} // override operator to use std::find
    friend std::ostream & operator<<(std::ostream &out, const Position &c){return out << (char)(c.column + 65) << c.row + 1 << std::endl;}; // output position and figure name

    std::string toString(){
        return std::to_string(column) + std::to_string(row);
    }
};


const int ROW_MIN = 0;
const int COLUMN_MIN = 0;
const int ROW_MAX = 8;
const int COLUMN_MAX = 8;


class Piece{
private:
    std::string           figure_name; // name of figure to transfer to frontend
    PieceColor            color = BLACK; // color of figure
    Position              position; // position on board, consists od column and row
    int                   column; // vertical position of figure
    int                   row; // horizontal position of figure
    bool                  occupied = true; // is square occupied
    bool                  moved = false; // was figure moved, used to castle and en passant pawn move
    std::vector<Position> moves; // vector of possible moves

public:
    Piece(const int,const int,const PieceColor, std::string);
    Piece(const Position,const PieceColor,const std::string){};
    Piece(const Piece &piece_);

    void setColor(const PieceColor); // set color of figure
    void setRow(const int); // set figure row
    void setColumn(const int); // set figure column
    void setPosition(const Position); // set figure position (column and row)
    void setMoved(bool moved); // set if piece moved
    void setOccupied(const bool); // set square occupied
    void setMoves(const std::vector<Position>); // set possible moves
    void setFigureName(const std::string); // set figure name
    bool isChecking(const Position position_piece,const Position position_king) const;

    std::vector<Position> evaluateCheck(const std::shared_ptr<BaseBoard>,const bool) const;
    virtual std::vector<Position> getPossibleMoves (std::shared_ptr<BaseBoard>,const bool =true) = 0; // get vector of possible moves
    virtual double getPositionValue() const = 0;


    PieceColor            getColor() const; // get color of figure
    int                   getColumn() const; // get column of figure
    int                   getRow() const; // get row of piece
    Position              getPosition() const; // get position of piece (column and row)
    bool                  getMoved() const; // set figure moved
    bool                  getOccupied() const; // is square occupied
    std::vector<Position> getMoves() const; // get possible moves of figure
    std::string           getFigureName() const; // get figure name

    friend std::ostream & operator<<(std::ostream &out, const Piece &c){return out << c.column << c.row << c.figure_name << std::endl;}; // output position and figure name
};
#endif