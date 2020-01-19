#include "lib/Square.h"
#include <memory>

Square::Square(std::shared_ptr<Piece> p){
    piece = p;
}

std::shared_ptr<Piece> Square::getPiece() const{
	return piece;
}

void Square::setPiece(std::shared_ptr<Piece> p) {
	piece = p;
}

int Square::getColumn() const{
	return column;
}

void Square::setColumn(int col) {
	column = col;
}

int Square::getRow() const{
	return row;
}

void Square::setRow(int r) {
	row = r;
}

bool Square::getOccupied() const{
	return occupied;
}

void Square::setOccupied(bool occ){
	occupied = occ;
}

