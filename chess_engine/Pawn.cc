#include "lib/Pawn.h"
#include <memory>
#include "AI/PositionValue.h"



std::vector<Position> Pawn::getPossibleMoves(const std::shared_ptr<BaseBoard> board, bool original_evaluation){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <std::shared_ptr<Square>>> board_current = board->getBoard();
    std::vector<Position> possible_position; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();
    //check if pawn can move forward
    if(!(row_current + 1 * direction_of_move > 7 || row_current + 1 * direction_of_move < 0)){
            if(!(board_current[column_current][row_current + 1 * direction_of_move]->getOccupied())){
            //check if pawn can move 2 squares ahead
            if(!this->getMoved()){
                if(!(board_current[column_current][row_current + 2 * direction_of_move]->getOccupied())){
                    
                    position.column = column_current;
                    position.row    = row_current + 2 * direction_of_move;

                    possible_position.push_back(position);
                }
            }
            position.column = column_current;
            position.row    = row_current + 1 * direction_of_move;

            possible_position.push_back(position);
        }
    }


    //if pawn not exceeding board diagonally
    if (!(row_current + 1 * direction_of_move > 7 || row_current + 1 * direction_of_move < 0)){
        // pawn can go left
        if (!(column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
            std::shared_ptr<Square> left_diagonal_piece = board_current[column_current - 1 * direction_of_move][row_current + 1 * direction_of_move];
            if (left_diagonal_piece->getOccupied() && left_diagonal_piece->getPiece()->getColor() == -1 * direction_of_move){
                position.column = column_current - 1 * direction_of_move;
                position.row    = row_current + 1 * direction_of_move;

                possible_position.push_back(position);
            }
        }
        
        //pawn can go right
        if (!(column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
            std::shared_ptr<Square> right_diagonal_piece = board_current[column_current + 1 * direction_of_move][row_current + 1 * direction_of_move];
            if (right_diagonal_piece->getOccupied() && right_diagonal_piece->getPiece()->getColor() == -1 * direction_of_move){
                position.column = column_current + 1 * direction_of_move;
                position.row    = row_current + 1 * direction_of_move;

                possible_position.push_back(position);
            }       
        }
    }
    this->setMoves(possible_position);
    if (original_evaluation){
        possible_position = evaluateCheck(board, false);
        this->setMoves(possible_position);
    }
    return possible_position;

}

double Pawn::getPositionValue() const{
    PieceColor color = this->getColor();

    if(color == BLACK)
        return PositionValue::PawnEvalBlack[this->getRow()][this->getColumn()];
    else
        return PositionValue::PawnEvalWhite[this->getRow()][this->getColumn()];
}