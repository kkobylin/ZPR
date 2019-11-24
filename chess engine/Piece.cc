#include "lib/Piece.h"

void Piece::setColor(PieceColor color){
    this->color = color;
}

void Piece::setColumn(int column){
    if (column > COLUMN_MIN && column < COLUMN_MAX)
        this->column = column;
    else 
        throw "Out of boundries, should be contained in (" 
        + std::to_string(COLUMN_MIN) + ","
        + std::to_string(COLUMN_MAX) + "). Is: "
        + std::to_string(column);
}

void Piece::setRow(int row){
    if (row > COLUMN_MIN && row < COLUMN_MAX)
        this->row = row;
    else 
        throw "Out of boundries, should be contained in (" 
        + std::to_string(ROW_MIN) + ","
        + std::to_string(ROW_MAX) + "). Is: "
        + std::to_string(row);

}

void Piece::setKilled(bool killed){
    this->killed = killed;
}

bool Piece::isKilled(){
    return this->killed;
}

int Piece::getColumn(){
    return this->column;
}

int Piece::getRow(){
    return this->row;
}

PieceColor Piece::getColor(){
    return this->color;
}


Piece::Piece(int column, int row, PieceColor color){
    this->column = column;
    this->row    = row;
    this->color  = color;
}
