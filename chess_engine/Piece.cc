#include "lib/Piece.h"
#include "lib/BaseBoard.h"

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
Position Piece::getKing(std::shared_ptr<BaseBoard> board){
    PieceColor color = this->getColor();
    PieceColor pieceColor;

    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++ ){
            if (board->getBoard()[column][row]->getOccupied()){
                std::string piece = board->getBoard()[column][row]->getPiece()->getFigureName();
                if (piece == "K"){
                    pieceColor = board->getBoard()[column][row]->getPiece()->getColor();
                    if (color == pieceColor){
                        return board->getBoard()[column][row]->getPiece()->getPosition();
                    }
                }
            }
        }
    }
}

bool Piece::isChecking(Position positionPiece, Position positionKing){
    if (positionKing.column == positionPiece.column && positionKing.row == positionPiece.row){
        std::cout << "Moze bic" << std::endl;
        return true;
    }else{
        return false;
    }
}

std::vector<Position> Piece::evaluateCheck(std::shared_ptr<BaseBoard> boardInitial, bool originalEvaluation){
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions

    for (Position position : this->getMoves()){
        std::shared_ptr<BaseBoard> boardCopy (new BaseBoard(boardInitial->getBoardString()));
        board_type board = boardCopy->getBoard();

        int src_col = this->getColumn();
        int src_row = this->getRow();

        int dest_col = position.column;
        int dest_row = position.row;

        //update board
            //update destination Square
        board[dest_col][dest_row]->setPiece(board[src_col][src_row]->getPiece());
        board[dest_col][dest_row]->setOccupied(true);
        board[dest_col][dest_row]->getPiece()->setPosition(position); // aktualizacja pozycji figury
        board[dest_col][dest_row]->getPiece()->setMoved();

            //update source Square
        board[src_col][src_row]->setPiece(std::shared_ptr<Piece>{nullptr});
        board[src_col][src_row]->setOccupied(false);

        //Evaluating Board Created, now check if king is underCheck
        Position king = this->getKing(boardCopy);

        boardCopy->printBoardCout();
        PieceColor color = this->getColor();
        PieceColor opponentColor;
        if (color = WHITE){
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
                        std::cout << "krol:" << king.column << king.row << std::endl;
                        for (auto pos : board[column][row]->getPiece()->getPossibleMoves(boardCopy, false)){
                            
                            if (board[column][row]->getPiece()->isChecking(pos,king)){
                                safe = false;
                                break;
                            }
                        }
                    } 
                }
            }
        }
    if (safe){
        possiblePosition.push_back(position); 
    }

        

        

        
    }
    return possiblePosition;

}

