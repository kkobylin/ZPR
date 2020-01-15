#include "lib/Piece.h"
#include "lib/BaseBoard.h"

class Board;

void Piece::setColor(PieceColor color){
    this->color = color;
}

void Piece::setColumn(int column){
        this->column = column;
}

void Piece::setRow(int row){
        this->row = row;
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
Position Piece::getKing(std::shared_ptr<BaseBoard> board, PieceColor color){
    PieceColor pieceColor;

    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++ ){
            if (board->getBoard()[column][row]->getOccupied()){
                std::string piece = board->getBoard()[column][row]->getPiece()->getFigureName();
                if (piece == "K"){
                    pieceColor = board->getBoard()[column][row]->getPiece()->getColor();
                    if (color == pieceColor){
                        //std::cout << "krol" <<board->getBoard()[column][row]->getPiece()->getColumn() << board->getBoard()[column][row]->getPiece()->getRow() << color<< pieceColor << std::endl;
                        return board->getBoard()[column][row]->getPiece()->getPosition();
                    }
                }
            }
        }
    }
}

bool Piece::isChecking(Position positionPiece, Position positionKing){
    if (positionKing.column == positionPiece.column && positionKing.row == positionPiece.row){
        //std::cout << "Szach" << std::endl;
        return true;
    }else{
        //std::cout << "Nie Szach: " << positionPiece.column << positionPiece.row << std::endl;
        //std::cout << "Krol: " << positionKing.column << positionKing.row << std::endl;
        return false;
    }
}

std::vector<Position> Piece::evaluateCheck(std::shared_ptr<BaseBoard> boardInitial, bool originalEvaluation){
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions

    for (Position position : this->getMoves()){
        std::shared_ptr<BaseBoard> boardCopy (new BaseBoard(boardInitial->toString()));
        board_type board = boardCopy->getBoard();

        int src_col = this->getColumn();
        int src_row = this->getRow();

        int dest_col = position.column;
        int dest_row = position.row;


        boardCopy->updateBoard(dest_col,dest_row,src_col,src_row);      

        //Evaluating Board Created, now check if king is underCheck
        Position king = boardCopy->getKing(this->getColor());

        PieceColor color = this->getColor();
        PieceColor opponentColor;
        if (color == WHITE){
            opponentColor = BLACK;
        }else{
            opponentColor = WHITE;
        }

        bool safe = true;
        //iterate pieces by columns
        for (int column = 0; column < 8; column++){
            //iterate pieces by rows
            for (int row = 0; row < 8; row++ ){
                //check if on Square is piece
                if (board[column][row]->getOccupied()){
                    color = board[column][row]->getPiece()->getColor();
                    if (color == opponentColor){
                        for (auto pos : board[column][row]->getPiece()->getPossibleMoves(boardCopy, false)){
                            
                            if (board[column][row]->getPiece()->isChecking(pos,king)){
                                safe = false;
                                break;
                            }
                        }
                        if (!safe){
                            break; 
                        }
                    }
                    if (!safe){
                        break;
                    } 
                }
                if(!safe){
                    break;
                }
            }
            if(!safe){
                break;
            }
        }
    if (safe){
        possiblePosition.push_back(position);
        }
    }
    return possiblePosition;

}

