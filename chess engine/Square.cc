#include "lib/Square.h"

Square::Square(Piece piece){
    this.piece = piece;

}

	public Piece getPiece() {
		return this.piece;
	}

	public void setPiece(Piece piece) {
		this.piece = piece;
	}

	public int getColumn() {
		return this.column;
	}

	public void setColumn(int column) {
		this.column = column;
	}

	public int getRow() {
		return this.Row;
	}

	public void setRow(int row) {
		this.row = row;
	}

