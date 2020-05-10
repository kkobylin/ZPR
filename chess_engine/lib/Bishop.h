/**
 * @file Bishop.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class for bishop
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Board.h"

class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color);
    double getPositionValue() const override ;
};
#endif // BISHOP_H
