/**
 * @file Queen.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class for Queen
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(const int column,const int row,const PieceColor color);  
    double getPositionValue() const override ;
};
#endif //QUEEN_H
