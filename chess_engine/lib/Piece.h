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

    bool operator==(const Position pos1);
    bool operator!=(const Position pos1);
    Position operator+(Position pos1);
    Position operator*(int const &pos1);
    std::string toString();
};
std::ostream & operator<<(std::ostream &out, const Position &c);



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
    Piece(const int,const int,const PieceColor);
    Piece(const Position,const PieceColor){};
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
    virtual std::vector<Position> getPossibleMoves (std::shared_ptr<BaseBoard>,const bool =true); // get vector of possible moves
    virtual double getPositionValue() const = 0;

    void setRecursive();

    PieceColor isMoveValid(Position const &position, std::shared_ptr<BaseBoard> const &board) const;
    bool moveIsInBoard(Position const &position) const;
    void setDirectionOfMove(Position const &pos);
    bool getMoveRecursive() const;


    PieceColor            getColor() const; // get color of figure
    int                   getColumn() const; // get column of figure
    int                   getRow() const; // get row of piece
    Position              getPosition() const; // get position of piece (column and row)
    bool                  getMoved() const; // set figure moved
    bool                  getOccupied() const; // is square occupied
    std::vector<Position> getMoves() const; // get possible moves of figure
    std::string           getFigureName() const; // get figure name
};

std::ostream & operator<<(std::ostream &out, const Piece &c); // output position and figure name

#endif

