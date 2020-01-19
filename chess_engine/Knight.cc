#include "lib/Knight.h"
#include <memory>
#include "AI/PositionValue.h"

Knight::Knight(const int column,const int row,const PieceColor color) :
    Piece (column, row, color){
        setFigureName("N");
        setDirectionOfMove(Position{-1,2});
        setDirectionOfMove(Position{1,2});
        setDirectionOfMove(Position{2,1});
        setDirectionOfMove(Position{2,-1});
        setDirectionOfMove(Position{-2,1});
        setDirectionOfMove(Position{-2,-1});
        setDirectionOfMove(Position{1,-2});
        setDirectionOfMove(Position{-1,-2});
        setPieceValue(3); //experimental
    }

double Knight::getPositionValue() const{

    PieceColor color = getColor();
    if(color == BLACK)
        return (getPieceValue() + PositionValue::KnightEval[getRow()][getColumn()]) * (-1);
    else
        return (getPieceValue() + PositionValue::KnightEval[getRow()][getColumn()]);
}
