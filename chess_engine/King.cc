#include "lib/King.h"
#include <memory>
#include "AI/PositionValue.h"

King::King(const int column,const int row,const PieceColor color) :
    Piece (column, row, color){
        setFigureName("K");
        setDirectionOfMove(Position{1,-1});
        setDirectionOfMove(Position{1,0});
        setDirectionOfMove(Position{1,1});
        setDirectionOfMove(Position{0,1});
        setDirectionOfMove(Position{-1,1});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{-1,-1});
        setDirectionOfMove(Position{0,-1});
        pieceValue = 15; //experimental
    }

double King::getPositionValue() const{
    PieceColor color = getColor();

    if(color == BLACK)
        return (pieceValue + PositionValue::KingEvalBlack[getRow()][getColumn()]) * (-1);
    else
        return (pieceValue + PositionValue::KingEvalWhite[getRow()][getColumn()]);
}