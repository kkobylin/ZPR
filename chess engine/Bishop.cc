#include "lib/Bishop.h"

void Bishop::move(Position position, Board board){}



void Bishop::setPossibleMove(Board board){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <Piece *>> board_current = board.getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    // left forward

    int i = 1; // iterator for moves. In every 

    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  > 0 || 
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current - i * direction_of_move][row_current + i * direction_of_move];

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


    // right forward
    i = 1;
    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  > 0 || 
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current + i * direction_of_move][row_current + i * direction_of_move];

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
    // left backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  > 0 || 
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current - i * direction_of_move][row_current - i * direction_of_move];

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
    // right backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  > 0 || 
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current + i * direction_of_move][row_current - i * direction_of_move];

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
}