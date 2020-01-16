#include "lib/Queen.h"
#include <memory>
#include "AI/PositionValue.h"
/*
std::vector<Position>  Queen::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <std::shared_ptr<Square>>> board_current = board->getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    
    //Following loops checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element and breaks loop

    // left forward

    int i = 1; // iterator for moves. In every 

    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  < 0 ||
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - i * direction_of_move][row_current + i * direction_of_move];

        position.column = column_current - i * direction_of_move;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }


    // right forward
    i = 1;
    while (!(row_current + i * direction_of_move  > 7 || row_current + i * direction_of_move  < 0 ||
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + i * direction_of_move][row_current + i * direction_of_move];

        position.column = column_current + i * direction_of_move;
        position.row    = row_current + i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // left backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  < 0 ||
             column_current - i * direction_of_move > 7 || column_current - i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - i * direction_of_move][row_current - i * direction_of_move];

        position.column = column_current - i * direction_of_move;
        position.row    = row_current - i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }
    // right backward
    i = 1;
    while (!(row_current - i * direction_of_move  > 7 || row_current - i * direction_of_move  < 0 ||
             column_current + i * direction_of_move > 7 || column_current + i * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + i * direction_of_move][row_current - i * direction_of_move];

        position.column = column_current + i * direction_of_move;
        position.row    = row_current - i * direction_of_move;

        possiblePosition.push_back(position);

        i++;

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possiblePosition.pop_back();
            break;
        }
    }

    //forward
    i = 1;

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
        
        std::shared_ptr<Square> piece = board_current[column_current][row_current - i * direction_of_move];

        position.column = column_current;
        position.row    = row_current - i * direction_of_move;

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

    if (originalEvaluation){
        possiblePosition = evaluateCheck(board, false);
        this->setMoves(possiblePosition);
    }
    return possiblePosition;
}
*/
double Queen::getPositionValue(){

    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::QueenEval[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::QueenEval[this->getRow()][this->getColumn()];
}