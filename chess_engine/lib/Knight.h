/**
 * @file Knight.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class for Knight
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(const int column,const int row,const PieceColor color);
    double getPositionValue() const override ;
};
#endif //KNIGHT_H
