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
private:
    bool moved = false;

public:
    Rook(int column, int row, PieceColor color) :
    Piece (column, row, color){
        setFigureName("R");
        setRecursive();
        setDirectionOfMove(Position{1,0});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{0,1});
        setDirectionOfMove(Position{0,-1});
        };
    
    //std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard>, bool = true);
    double getPositionValue() override ;
};
#endif //ROOK_H
