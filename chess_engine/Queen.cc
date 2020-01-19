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
    }

double Queen::getPositionValue() const{

    PieceColor color = getColor();

    if(color == BLACK)
        return PositionValue::QueenEval[getRow()][getColumn()] * (-1);
    else
        return PositionValue::QueenEval[getRow()][getColumn()];
}