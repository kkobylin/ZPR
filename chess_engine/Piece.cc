#include "lib/Piece.h"

class Board;

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
    this->position.column = column;
    this->position.row = row;
}

Piece::Piece(int column, int row, PieceColor color, std::string figureName){
    this->column = column;
    this->row    = row;
    this->color  = color;
    this->position.column = column;
    this->position.row = row;
    this->figureName = figureName;
}

Piece::Piece(int column, int row, bool occupied){
    this->column = column;
    this->row    = row;
    this->position.column = column;
    this->position.row = row;
    this->occupied  = occupied;
}

Piece::Piece(int column, int row, bool occupied, std::string figureName){
    this->column = column;
    this->row    = row;
    this->position.column = column;
    this->position.row = row;
    this->occupied  = occupied;
    this->figureName = figureName;
}

bool Piece::getOccupied(){
    return this->occupied;
}

void Piece::setOccupied(bool occupied){
    this->occupied = occupied;
}

void Piece::setPosition(Position position){
    this->position = position;
    this->column = position.column;
    this->row = position.row;
}

Position Piece::getPosition(){
    return this->position;
}

bool Piece::getMoved(){
    return this->moved;
}

void Piece::setMoved(){
    this->moved = true;
}

void Piece::setMoves(std::vector<Position> possible_move){
    this->moves = possible_move;
}

//void Piece::move(Position position, Board board){};

void Piece::setFigureName(std::string figureName){
    this->figureName = figureName;
}

std::string Piece::getFigureName(){
    return this->figureName;
}

std::vector<Position> Piece::getMoves(){
    return this->moves;
}