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
private:
    bool moved = false;
public:
    Pawn(int column, int row, PieceColor color) :
        Piece (column, row, color){setFigureName("P");};
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool) override;
    
    double getPositionValue() override ;
};
#endif //PAWN_H
