#include "AI/PositionValue.h"
#include "lib/Bishop.h"

Bishop::Bishop(int column, int row, PieceColor color) :
    Piece (column, row, color){
        setFigureName("B");
        setRecursive();
        setDirectionOfMove(Position{1,1});
        setDirectionOfMove(Position{-1,1});
        setDirectionOfMove(Position{-1,-1});
        setDirectionOfMove(Position{1,-1});
        pieceValue = 3; //experimental
    }

double Bishop::getPositionValue() const{
    PieceColor color = getColor();

    if(color == BLACK)
        return (pieceValue + PositionValue::BishopEvalBlack[getRow()][getColumn()]) * (-1);
    else
        return (pieceValue + PositionValue::BishopEvalWhite[getRow()][getColumn()]);
}