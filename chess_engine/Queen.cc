/**
 * @file Queen.cc
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "lib/Queen.h"
#include <memory>
#include "AI/PositionValue.h"

Queen::Queen(const int column,const int row,const PieceColor color) :
    Piece (column, row, color){
        setFigureName("Q");
        setRecursive();
        setDirectionOfMove(Position{1,-1});
        setDirectionOfMove(Position{1,0});
        setDirectionOfMove(Position{1,1});
        setDirectionOfMove(Position{0,1});
        setDirectionOfMove(Position{-1,1});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{-1,-1});
        setDirectionOfMove(Position{0,-1});
        setPieceValue(9); //experimental
    }

double Queen::getPositionValue() const{

    PieceColor color = getColor();

    if(color == BLACK)
        return (getPieceValue() + PositionValue::QueenEval[getRow()][getColumn()]) * (-1);
    else
        return (getPieceValue() + PositionValue::QueenEval[getRow()][getColumn()]);
}