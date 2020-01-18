#include "lib/King.h"
#include <memory>
#include "AI/PositionValue.h"


double King::getPositionValue() const{
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::KingEvalBlack[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::KingEvalWhite[this->getRow()][this->getColumn()];
}