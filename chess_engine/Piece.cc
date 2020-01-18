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


int Piece::getColumn() const{
    return this->column;
}

int Piece::getRow() const{
    return this->row;
}

PieceColor Piece::getColor() const{
    return this->color;
}


Piece::Piece(int column, int row, PieceColor color){
    this->column = column;
    this->row    = row;
    this->color  = color;
    this->position.column = column;
    this->position.row = row;
}

Piece::Piece(const Piece &piece_) {
    this->column = piece_.getColumn();
    this->row    = piece_.getRow();
    this->color  = piece_.getColor();
    this->position.column = piece_.getColumn();
    this->position.row = piece_.getRow();
    this->figure_name = piece_.getFigureName();
}

bool Piece::getOccupied() const{
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

Position Piece::getPosition() const{
    return this->position;
}

bool Piece::getMoved() const{
    return this->moved;
}

void Piece::setMoved(bool moved){
    this->moved = moved;
}

void Piece::setMoves(std::vector<Position> possible_move){
    this->moves = possible_move;
}

//void Piece::move(Position position, Board board){};

void Piece::setFigureName(std::string figure_name){
    this->figure_name = figure_name;
}

std::string Piece::getFigureName() const{
    return this->figure_name;
}

std::vector<Position> Piece::getMoves() const{
    return this->moves;
}

Position Piece::getKing(std::shared_ptr<BaseBoard> board, PieceColor piece_color){

    for (int column = COLUMN_MIN; column < COLUMN_MAX; column++){
        for (int row = ROW_MIN; row < ROW_MAX; row++ ){
            if (board->getBoard()[column][row]->getOccupied()){
                std::string piece = board->getBoard()[column][row]->getPiece()->getFigureName();
                if (piece == "K"){
                    piece_color = board->getBoard()[column][row]->getPiece()->getColor();
                    if (piece_color == piece_color){
                        return board->getBoard()[column][row]->getPiece()->getPosition();
                    }
                }
            }
        }
    }
}

bool Piece::isChecking(Position position_piece, Position position_king) const{
    if (position_king.column == position_piece.column && position_king.row == position_piece.row){
        return true;
    }else{
        return false;
    }
}

std::vector<Position> Piece::evaluateCheck(std::shared_ptr<BaseBoard> board_initial, bool original_evaluation) const{
    std::vector<Position> possible_position; //Create buffer for computed possible positions

    for (Position position : this->getMoves()){
        std::shared_ptr<BaseBoard> board_copy (new BaseBoard(board_initial->toString()));
        board_type board = board_copy->getBoard();

        int src_col = this->getColumn();
        int src_row = this->getRow();

        int dest_col = position.column;
        int dest_row = position.row;


        board_copy->updateBoard(dest_col, dest_row, src_col, src_row);

        //Evaluating Board Created, now check if king is underCheck
        Position king = board_copy->getKing(this->getColor());

        PieceColor color = this->getColor();
        PieceColor opponent_color;
        if (color == WHITE){
            opponent_color = BLACK;
        }else{
            opponent_color = WHITE;
        }

        bool safe = true;
        //iterate pieces by columns
        for (int column = COLUMN_MIN; column < COLUMN_MAX; column++ ){
            //iterate pieces by rows
            for (int row = ROW_MIN; row < ROW_MAX; row++ ){
                //check if on Square is piece
                if (board[column][row]->getOccupied()){
                    color = board[column][row]->getPiece()->getColor();
                    if (color == opponent_color){
                        for (auto pos : board[column][row]->getPiece()->getPossibleMoves(board_copy, false)){
                            
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
        possible_position.push_back(position);
        }
    }
    return possible_position;

}

PieceColor Piece::isMoveValid(Position position, std::shared_ptr<BaseBoard> board){
    std::shared_ptr<Square> piece = board->getBoard()[position.column][position.row];

    if (piece->getOccupied()){
        if(piece->getPiece()->getColor() == color){
            return color;
        }else{
            return static_cast<PieceColor>(-1*color);
        }
    }else{
        return NONE;
    }
}

bool Piece::moveIsInBoard(Position position){
    if (position.column >= 0 && position.column < 8 && position.row >= 0 && position.row < 8){
        return true;
    }else{
        return false;
    }
}

std::vector<Position> Piece::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    std::vector<Position> possible_position;
    if(isMoveRecursive){
        for (auto move_scheme : directionOfMoves){
            Position dest_square = position + move_scheme;
            int i = 1;
            while(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != color){
                possible_position.push_back(dest_square);
                ++i;
                if (isMoveValid(dest_square, board) == static_cast<PieceColor>(-1*color)){
                    break;
                }
                dest_square = position + (move_scheme * i);
            }
        }
    }else{
        for (auto move_scheme : directionOfMoves){
            Position dest_square = position + move_scheme;
            if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != color){
                possible_position.push_back(dest_square);
            }
        } 
    }

    setMoves(possible_position);

    if (originalEvaluation){
        possible_position = evaluateCheck(board, false);
        setMoves(possible_position);
    }
    /*
    if (originalEvaluation && getColor() == BLACK)
        for (auto a: possible_position){
            std::cout << "mozliwy ruch dla: " << *this << " " << a << std::endl;
        }
        */
    return possible_position;
}

void Piece::setRecursive(){
    isMoveRecursive = true;
}
// todo getrecursive
void Piece::setDirectionOfMove(Position pos){
    directionOfMoves.push_back(pos);

}