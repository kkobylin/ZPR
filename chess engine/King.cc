#include "lib/King.h"

bool King::getMoved(){
        return this->moved;
}

void King::setMoved(bool moved){
        this->moved = moved;
}

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
void King::move(Position position, Board board){}