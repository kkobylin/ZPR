#include "lib/Square.h"

Square::Square(Piece * piece){
    this->piece = piece;

}

	Piece * Square::getPiece() {
		return this->piece;
	}

	void Square::setPiece(Piece * piece) {
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

