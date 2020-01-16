#include "lib/King.h"
#include <memory>
#include "AI/PositionValue.h"


bool King::getCastled(){
        return this->castled;
}

void King::setCastled(bool castled){
        this->castled = castled;
}

bool King::getChecked(){
        return this->checked;
}

void King::setChecked(bool checked){
        this->checked = checked;
}



double King::getPositionValue(){
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::KingEvalBlack[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::KingEvalWhite[this->getRow()][this->getColumn()];
}