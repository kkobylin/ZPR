#include "lib/Square.h"
#include <memory>

Square::Square(std::shared_ptr<Piece> piece){
    this->piece = piece;
}

std::shared_ptr<Piece> Square::getPiece() const{
	return this->piece;
}

void Square::setPiece(std::shared_ptr<Piece> piece) {
	this->piece = piece;
}

int Square::getColumn() const{
	return this->column;
}

void Square::setColumn(int column) {
	this->column = column;
}

int Square::getRow() const{
	return this->row;
}

void Square::setRow(int row) {
	this->row = row;
}

bool Square::getOccupied() const{
	return occupied;
}

void Square::setOccupied(bool occupied){
	this->occupied = occupied;
}

