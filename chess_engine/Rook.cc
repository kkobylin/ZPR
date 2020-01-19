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
        pieceValue = 5; //experimental
    }

double Rook::getPositionValue() const{
    PieceColor color = getColor();

    if(color == BLACK)
        return (pieceValue + PositionValue::RookEvalBlack[getRow()][getColumn()]) * (-1);
    else
        return (pieceValue + PositionValue::RookEvalWhite[getRow()][getColumn()]);
}