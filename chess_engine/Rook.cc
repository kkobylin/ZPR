/**
 * @file Rook.cc
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "lib/Rook.h"
#include <memory>
#include "AI/PositionValue.h"

Rook::Rook(const int column,const int row,const PieceColor color) :
    Piece (column, row, color){
        setFigureName("R");
        setRecursive();
        setDirectionOfMove(Position{1,0});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{0,1});
        setDirectionOfMove(Position{0,-1});
        setPieceValue(5); //experimental
    }

double Rook::getPositionValue() const{
    PieceColor color = getColor();

    if(color == BLACK)
        return (getPieceValue() + PositionValue::RookEvalBlack[getRow()][getColumn()]) * (-1);
    else
        return (getPieceValue() + PositionValue::RookEvalWhite[getRow()][getColumn()]);
}