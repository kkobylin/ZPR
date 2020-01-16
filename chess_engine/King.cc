#include "lib/King.h"
#include <memory>
#include "AI/PositionValue.h"


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

/*
std::vector<Position>  King::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <std::shared_ptr<Square>>> board_current = board->getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    //Following ifs checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element

    // left forward


    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 1 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // right forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 || 
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 1 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 1 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 1 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }

    //forward
    

    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current][row_current + 1 * direction_of_move];

        position.column = column_current;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // backward 
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current][row_current - 1 * direction_of_move];

        position.column = column_current;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left
    
    if (!(column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 1 * direction_of_move][row_current];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right
    
    if (!(column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 1 * direction_of_move][row_current];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }

    //todo castle 


    this->setMoves(possiblePosition);

    if (originalEvaluation){
        possiblePosition = evaluateCheck(board, false);
        this->setMoves(possiblePosition);
    }
    return possiblePosition;
}
*/

double King::getPositionValue(){
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::KingEvalBlack[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::KingEvalWhite[this->getRow()][this->getColumn()];
}