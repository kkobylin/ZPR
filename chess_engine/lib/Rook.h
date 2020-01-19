/**
 * @file Rook.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "Board.h"


class Rook : public Piece{
public:
    Rook(const int column,const int row,const PieceColor color);
    double getPositionValue() const override ;
};
#endif //ROOK_H
