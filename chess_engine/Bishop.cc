#include <AI/PositionValue.h>
#include "lib/Bishop.h"

void Bishop::move(Position position, Board board){} // todo

std::vector<Position> Bishop::getPossibleMoves(){
    
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::shared_ptr<Board> board = Board::getInstance();
    std::vector<std::vector <std::shared_ptr<Piece>>> board_current = board->getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    //Following loops checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element and breaks loop

    // check how far can bishop move in direction: left forward

    int i = 1; // iterator for next moves


    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  < 0 ||
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - i * direction_of_move][row_current + i * direction_of_move];

        position.column = column_current - i * direction_of_move;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }


    // check how far can bishop move in direction: right forward
    i = 1;
    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  < 0 ||
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + i * direction_of_move][row_current + i * direction_of_move];

        position.column = column_current + i * direction_of_move;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // check how far can bishop move in direction: left backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  < 0 ||
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - i * direction_of_move][row_current - i * direction_of_move];

        position.column = column_current - i * direction_of_move;
        position.row    = row_current - i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // check how far can bishop move in direction: right backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  < 0 ||
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + i * direction_of_move][row_current - i * direction_of_move];

        position.column = column_current + i * direction_of_move;
        position.row    = row_current - i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }


    this->setMoves(possiblePosition);
    return possiblePosition;
}

double Bishop::getPositionValue(){
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::BishopEvalBlack[this->getRow()][this->getColumn()];
    else
        return PositionValue::BishopEvalWhite[this->getRow()][this->getColumn()];
}