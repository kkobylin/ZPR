#include "lib/King.h"

bool King::getMoved(){
        return this->moved;
}

void King::setMoved(bool moved){
        this->moved = moved;
}

bool King::getCastled(){
        return this->castled;
}

void King::setCastled(bool castled){
        this->castled = castled;
}

bool King::getChecked(){
        return this->checked;
}

void King::setChecked(bool checked){
        this->checked = checked;
}
void King::move(Position position, Board board){}

void King::setPossibleMove(Board board){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <Piece *>> board_current = board.getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    // left forward


    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  > 0 || 
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current - 1 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // right forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  > 0 || 
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current + 1 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  > 0 || 
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current - 1 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  > 0 || 
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current + 1 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }

    //forward
    

    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  > 0)){
        
        Piece * piece = board_current[column_current][row_current + 1 * direction_of_move];

        position.column = column_current;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // backward 
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  > 0)){
        
        Piece * piece = board_current[column_current][row_current + 1 * direction_of_move];

        position.column = column_current;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left
    
    if (!(column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current - 1 * direction_of_move][row_current];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right
    
    if (!(column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move > 0)){
        
        Piece * piece = board_current[column_current + 1 * direction_of_move][row_current];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }

    //todo castle 


    this->setMoves(possiblePosition);
}