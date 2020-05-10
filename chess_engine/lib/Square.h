/**
 * @file Square.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class holding piece on the board
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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
    void setOccupied(const bool); ///< set Square occupied (Piece on Square)

    std::shared_ptr<Piece> getPiece() const;
    int   getRow() const;
    int   getColumn() const;
    bool getOccupied() const; ///< is any piece on Square

};
#endif
