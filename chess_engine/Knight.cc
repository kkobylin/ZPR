#include "lib/Knight.h"
#include <memory>

void Knight::move(Position position, Board board){}
std::vector<Position>  Knight::getPossibleMoves(){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::shared_ptr<Board> board = Board::getInstance();
    std::vector<std::vector <std::shared_ptr<Piece>>> board_current = board->getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    //Following ifs checks wheter possible next move doesn't exceed board, if not adds it to vector of possible move,
    //than checks is square is occupied, if it is and it's the same color it deletes last element

    // forward left


    if (!(row_current + 2 * direction_of_move  > 7 || row_current + 2 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - 1 * direction_of_move][row_current + 2 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current + 2 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // forward right
    
    if (!(row_current + 2 * direction_of_move  > 7 || row_current + 2 * direction_of_move  < 0 ||
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + 1 * direction_of_move][row_current + 2 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current + 2 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 ||
             column_current - 2 * direction_of_move > 7 || column_current - 2 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - 2 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current - 2 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // left backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current - 2 * direction_of_move > 7 || column_current - 2 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - 2 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current - 2 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }

    // backward left


    if (!(row_current - 2 * direction_of_move  > 7 || row_current - 2 * direction_of_move  < 0 ||
             column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current - 1 * direction_of_move][row_current - 2 * direction_of_move];

        position.column = column_current - 1 * direction_of_move;
        position.row    = row_current - 2 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    // backward right
    
    if (!(row_current - 2 * direction_of_move  > 7 || row_current - 2 * direction_of_move  < 0 ||
             column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + 1 * direction_of_move][row_current - 2 * direction_of_move];

        position.column = column_current + 1 * direction_of_move;
        position.row    = row_current - 2 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right forward
    
    if (!(row_current + 1 * direction_of_move  > 7 || row_current + 1 * direction_of_move  < 0 ||
             column_current + 2 * direction_of_move > 7 || column_current + 2 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + 2 * direction_of_move][row_current + 1 * direction_of_move];

        position.column = column_current + 2 * direction_of_move;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }
    // right backward
    
    if (!(row_current - 1 * direction_of_move  > 7 || row_current - 1 * direction_of_move  < 0 ||
             column_current + 2 * direction_of_move > 7 || column_current + 2 * direction_of_move < 0)){
        
        std::shared_ptr<Piece> piece = board_current[column_current + 2 * direction_of_move][row_current - 1 * direction_of_move];

        position.column = column_current + 2 * direction_of_move;
        position.row    = row_current - 1 * direction_of_move;

        possiblePosition.push_back(position);

        if (piece->getOccupied()){
            if(piece->getColor() == direction_of_move)
                possiblePosition.pop_back();
            
        }
    }


    this->setMoves(possiblePosition);
    return possiblePosition;
}
