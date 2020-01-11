#include "lib/Rook.h"
#include <memory>
#include <AI/PositionValue.h>

bool Rook::getMoved(){
    return this->moved;
}

void Rook::setMoved(bool moved){
    this->moved = moved;
}

void Rook::move(Position position, Board board){}
std::vector<Position>  Rook::getPossibleMoves(){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::shared_ptr<Board> board = Board::getInstance();
    std::vector<std::vector <std::shared_ptr<Square>>> board_current = board->getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    
    //Following loops checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element and breaks loop

    //forward

    int i = 1; // iterator for moves. In every 

    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current][row_current + i * direction_of_move];

        position.column = column_current;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }


    // backward 
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current][row_current + i * direction_of_move];

        position.column = column_current;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // left
    i = 1;
    while (!(column_current - i * direction_of_move > 7 || column_current - i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - i * direction_of_move][row_current];

        position.column = column_current - i * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // right
    i = 1;
    while (!(column_current + i * direction_of_move > 7 || column_current + i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + i * direction_of_move][row_current];

        position.column = column_current + i * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }


    this->setMoves(possiblePosition);
    return possiblePosition;
}

double Rook::getPositionValue(){
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::RookEvalBlack[this->getRow()][this->getColumn()];
    else
        return PositionValue::RookEvalWhite[this->getRow()][this->getColumn()];
}