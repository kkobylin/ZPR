#include "lib/Rook.h"
#include <memory>
#include "AI/PositionValue.h"


double Rook::getPositionValue() const{
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::RookEvalBlack[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::RookEvalWhite[this->getRow()][this->getColumn()];
}