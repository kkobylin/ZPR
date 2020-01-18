#include "lib/Queen.h"
#include <memory>
#include "AI/PositionValue.h"

double Queen::getPositionValue() const{

    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::QueenEval[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::QueenEval[this->getRow()][this->getColumn()];
}