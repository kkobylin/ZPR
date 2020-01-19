/**
 * @file King.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Board.h"

class King : public Piece{
private:

public:
    King(const int column,const int row,const PieceColor color);
    double getPositionValue() const override ;
};
#endif //KING_H
