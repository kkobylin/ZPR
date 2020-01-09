#include "lib/Square.h"
#include <memory>

Square::Square(std::shared_ptr<Piece> piece){
    this->piece = piece;

}

	std::shared_ptr<Piece> Square::getPiece() {
		return this->piece;
	}

	void Square::setPiece(std::shared_ptr<Piece> piece) {
		this->piece = piece;
	}

	int Square::getColumn() {
		return this->column;
	}

	void Square::setColumn(int column) {
		this->column = column;
	}

	int Square::getRow() {
		return this->row;
	}

	void Square::setRow(int row) {
		this->row = row;
	}

	bool Square::getOccupied(){
		return occupied;
	}

	void Square::setOccupied(bool occupied){
		this->occupied = occupied;
	}

