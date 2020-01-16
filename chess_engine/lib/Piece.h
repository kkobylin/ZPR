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
    NONE = 0,
    WHITE = 1
};

struct Position{
    int column = -1;
    int row = -1;

    bool operator==(Position pos1){ return pos1.column == column && pos1.row == row;} // override operator to use std::find
    bool operator!=(Position pos1){ return pos1.column != column || pos1.row != row;} // override operator to use std::find
    Position operator+(Position pos1){ return Position{pos1.column + column, pos1.row + row};}
    Position operator*(int const &pos1){ return Position{pos1 * column, pos1 * row};}
    
    friend std::ostream & operator<<(std::ostream &out, const Position &c){return out << (char)(c.column + 65) << c.row + 1;}; // output position and figure name

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


    std::vector<Position> directionOfMoves;
    bool isMoveRecursive = false;

public:
    Piece(int, int, PieceColor);
    Piece(Position, PieceColor){};

    void setColor(PieceColor); // set color of figure
    void setRow(int); // set figure row
    void setColumn(int); // set figure column
    void setPosition(Position); // set figure position (column and row)
    void setMoved(); // set if piece moved
    void setOccupied(bool); // set square occupied
    void setMoves(std::vector<Position>); // set possible moves
    void setFigureName(std::string); // set figure name
    bool isChecking(Position positionPiece, Position positionKing);
    Position getKing(std::shared_ptr<BaseBoard>, PieceColor pieceColor);
    std::vector<Position> evaluateCheck(std::shared_ptr<BaseBoard> board, bool initialboard);
    virtual std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool = true); // get vector of possible moves
    virtual double getPositionValue() = 0;
    void setRecursive();

    PieceColor isMoveValid(Position position, std::shared_ptr<BaseBoard> board);
    bool moveIsInBoard(Position position);
    void setDirectionOfMove(Position pos);


    PieceColor            getColor(); // get color of figure
    int                   getColumn(); // get column of figure
    int                   getRow(); // get row of piece
    Position              getPosition(); // get position of piece (column and row)
    bool                  getMoved(); // set figure moved
    bool                  getOccupied(); // is square occupied
    std::vector<Position> getMoves(); // get possible moves of figure
    std::string           getFigureName(); // get figure name

    friend std::ostream & operator<<(std::ostream &out, const Piece &c){return out << c.column << c.row << c.figure_name << std::endl;}; // output position and figure name
};
#endif

