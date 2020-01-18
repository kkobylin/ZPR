#include "AI/PositionValue.h"
#include "lib/Bishop.h"


double Bishop::getPositionValue() const{
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::BishopEvalBlack[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::BishopEvalWhite[this->getRow()][this->getColumn()];
}