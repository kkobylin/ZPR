#include "lib/Piece.h"
#include "lib/BaseBoard.h"

class Board;


bool Position::operator==(const Position pos1){
    return pos1.column == column && pos1.row == row;
}
bool Position::operator!=(const Position pos1){
    return pos1.column != column || pos1.row != row;
}
std::ostream & operator<<(std::ostream &out, const Position &c){
    return out << (char)(c.column + 65) << c.row + 1 << std::endl;
}
std::ostream & operator<<(std::ostream &out, const Piece &c){
    return out << (char)(c.getColumn() + 65) << c.getRow() + 1 << c.getFigureName() << std::endl;
}
Position Position::operator+(Position pos1){
    return Position{pos1.column + column, pos1.row + row};
} 
Position Position::operator*(int const &pos1){
    return Position{pos1 * column, pos1 * row};
} 
std::string Position::toString(){
    return std::to_string(column) + std::to_string(row);
}




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

PieceColor Piece::isMoveValid(Position const &position, std::shared_ptr<BaseBoard> const &board) const{
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

bool Piece::moveIsInBoard(Position const &position) const{
    if (position.column >= 0 && position.column < 8 && position.row >= 0 && position.row < 8){
        return true;
    }else{
        return false;
    }
}
bool Piece::getMoveRecursive() const{
    return isMoveRecursive;
}

std::vector<Position> Piece::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    std::vector<Position> possible_position;
    if(getMoveRecursive()){
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
    return possible_position;
}

void Piece::setRecursive(){
    isMoveRecursive = true;
}
void Piece::setDirectionOfMove(Position const &pos){
    directionOfMoves.push_back(pos);
}

