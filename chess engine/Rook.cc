#include "lib/Rook.h"

bool Rook::getMoved(){
    return this->moved;
}

void Rook::setMoved(bool moved){
    this->moved = moved;
}

void Rook::move(Position position, Board board){}