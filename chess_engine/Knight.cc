#include "lib/Knight.h"
#include <memory>
#include "AI/PositionValue.h"

double Knight::getPositionValue() const{

    PieceColor color = this->getColor();
    if(color == BLACK)
        return PositionValue::KnightEval[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::KnightEval[this->getRow()][this->getColumn()];
}
