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

Piece::Piece(int column, int row, PieceColor color, std::string figure_name){
    this->column = column;
    this->row    = row;
    this->color  = color;
    this->position.column = column;
    this->position.row = row;
    this->figure_name = figure_name;
}

Piece::Piece(int column, int row, bool occupied){
    this->column = column;
    this->row    = row;
    this->position.column = column;
    this->position.row = row;
    this->occupied  = occupied;
}

Piece::Piece(int column, int row, bool occupied, std::string figure_name){
    this->column = column;
    this->row    = row;
    this->position.column = column;
    this->position.row = row;
    this->occupied  = occupied;
    this->figure_name = figure_name;
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

void Piece::setFigureName(std::string figure_name){
    this->figure_name = figure_name;
}

std::string Piece::getFigureName(){
    return this->figure_name;
}

std::vector<Position> Piece::getMoves(){
    return this->moves;
}
Position Piece::getKing(std::shared_ptr<BaseBoard> board){
    PieceColor color = this->getColor();
    PieceColor piece_color;

    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++ ){
            if (board->getBoard()[column][row]->getOccupied()){
                std::string piece = board->getBoard()[column][row]->getPiece()->getFigureName();
                if (piece == "K"){
                    piece_color = board->getBoard()[column][row]->getPiece()->getColor();
                    if (color == piece_color){
                        //std::cout << "krol" <<board->getBoard()[column][row]->getPiece()->getColumn() << board->getBoard()[column][row]->getPiece()->getRow() << color<< piece_color << std::endl;
                        return board->getBoard()[column][row]->getPiece()->getPosition();
                    }
                }
            }
        }
    }
}

bool Piece::isChecking(Position position_piece, Position position_king){
    if (position_king.column == position_piece.column && position_king.row == position_piece.row){
        //std::cout << "Szach" << std::endl;
        return true;
    }else{
        //std::cout << "Nie Szach: " << position_piece.column << position_piece.row << std::endl;
        //std::cout << "Krol: " << position_king.column << position_king.row << std::endl;
        return false;
    }
}

std::vector<Position> Piece::evaluateCheck(std::shared_ptr<BaseBoard> board_initial, bool original_evaluation){
    std::vector<Position> possible_position; //Create buffer for computed possible positions

    for (Position position : this->getMoves()){
        std::shared_ptr<BaseBoard> boardCopy (new BaseBoard(board_initial->toString()));
        board_type board = boardCopy->getBoard();

        int src_col = this->getColumn();
        int src_row = this->getRow();

        int dest_col = position.column;
        int dest_row = position.row;


        boardCopy->updateBoard(dest_col,dest_row,src_col,src_row);      

        //Evaluating Board Created, now check if king is underCheck
        Position king = this->getKing(boardCopy);

        PieceColor color = this->getColor();
        PieceColor opponent_color;
        if (color == WHITE){
            opponent_color = BLACK;
        }else{
            opponent_color = WHITE;
        }

        bool safe = true;
        //iterate pieces by columns
        for (int column = 0; column < 8; column++){
            //iterate pieces by rows
            for (int row = 0; row < 8; row++ ){
                //check if on Square is piece
                if (board[column][row]->getOccupied()){
                    color = board[column][row]->getPiece()->getColor();
                    if (color == opponent_color){
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
        possible_position.push_back(position);
        }
    }
    return possible_position;

}

