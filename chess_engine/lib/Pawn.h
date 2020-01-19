/**
 * @file Pawn.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Board.h"
#include <algorithm>
#include <iostream>

class Pawn : public Piece{
public:
    Pawn(int column, int row, PieceColor color);
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool = true);
    
    double getPositionValue() const override ;
};
#endif //PAWN_H
