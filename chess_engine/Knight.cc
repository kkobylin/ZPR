#include "lib/Knight.h"
#include <memory>
#include "AI/PositionValue.h"


std::vector<Position>  Knight::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool original_evaluation){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <std::shared_ptr<Square>>> board_current = board->getBoard();
    std::vector<Position> possible_position; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    //Following ifs checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element

    // forward left


    if (!(row_current + 2 * direction_of_move  > 7 || row_current + 2 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 1 * direction_of_move][row_current + 2 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current + 2 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }


    // forward right
    
    if (!(row_current + 2 * direction_of_move  > 7 || row_current + 2 * direction_of_move  < 0 ||
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 1 * direction_of_move][row_current + 2 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current + 2 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }
    // left forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 ||
             column_current - 2 * direction_of_move > 7 || column_current - 2 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 2 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current - 2 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }
    // left backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current - 2 * direction_of_move > 7 || column_current - 2 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 2 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current - 2 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }

    // backward left


    if (!(row_current - 2 * direction_of_move  > 7 || row_current - 2 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current - 1 * direction_of_move][row_current - 2 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current - 2 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }


    // backward right
    
    if (!(row_current - 2 * direction_of_move  > 7 || row_current - 2 * direction_of_move  < 0 ||
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 1 * direction_of_move][row_current - 2 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current - 2 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }
    // right forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 ||
             column_current + 2 * direction_of_move > 7 || column_current + 2 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 2 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current + 2 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }
    // right backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current + 2 * direction_of_move > 7 || column_current + 2 * direction_of_move < 0)){
        
        std::shared_ptr<Square> piece = board_current[column_current + 2 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current + 2 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possible_position.push_back(position);

        if (piece->getOccupied()){
            if(piece->getPiece()->getColor() == direction_of_move)
                possible_position.pop_back();
            
        }
    }


    this->setMoves(possible_position);

    if (original_evaluation){
        possible_position = evaluateCheck(board, false);
        this->setMoves(possible_position);
    }
    return possible_position;
}

double Knight::getPositionValue() const{

    PieceColor color = this->getColor();
    if(color == BLACK)
        return PositionValue::KnightEval[this->getRow()][this->getColumn()] * (-1);
    else
        return PositionValue::KnightEval[this->getRow()][this->getColumn()];
}
