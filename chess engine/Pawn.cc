#include "lib/Pawn.h"



/* Pawn::setMoved(){
    this->moved = true;
}*/
void Pawn::move(Position position, Board board){
    this->setPossibleMove(board);
    std::vector<Position> position_vector = this->getMoves();
    std::vector<Position>::iterator it = std::find(position_vector.begin(),
                                                   position_vector.end(), 
                                                   position);
    if (it != position_vector.end()){
            setColumn(position.column);
            setRow(position.row);
            std::cout << "good";

    }else
            {
                std::cout << "blad";
            }
            

}/*
Pawn::getPossibleNextMove(Board board){
if (isMoved)
    
} */

void Pawn::setPossibleMove(Board board){
    int column_current = this->getColumn();
    int row_current    = this->getRow();
    int color          = this->getColor();
    std::vector<std::vector <Piece *>> board_current = board.getBoard();
    std::vector<Position> possiblePosition; //Create buffer for computed possible positions
    Position position;

    int direction_of_move = this->getColor();

    //sprawdzenie możliwości ruchu
    if(!board_current[column_current][row_current + 1 * direction_of_move]->getOccupied()){
        position.column = column_current;
        position.row    = row_current + 1 * direction_of_move;

        possiblePosition.push_back(position);
    }
    if(!this->getMoved())
        if(!board_current[column_current][row_current + 2 * direction_of_move]->getOccupied()){
            position.column = column_current;
            position.row    = row_current + 2 * direction_of_move;

            possiblePosition.push_back(position);
        }




    //if pawn not exceeding board diagonally
    if (!(row_current + 1 * direction_of_move > 7 || row_current + 1 * direction_of_move < 0)){
        // pawn can go left
        if (!(column_current - 1 * direction_of_move > 7 || column_current - 1 * direction_of_move < 0)){
            Piece * left_diagonal_piece = board_current[column_current - 1 * direction_of_move][row_current + 1 * direction_of_move];
            if (left_diagonal_piece->getOccupied() && left_diagonal_piece->getColor() == -1 * direction_of_move){
                position.column = column_current - 1 * direction_of_move;
                position.row    = row_current + 1 * direction_of_move;

                possiblePosition.push_back(position);
            }
        }
        //pawn can go right
        if (!(column_current + 1 * direction_of_move > 7 || column_current + 1 * direction_of_move < 0)){
            Piece * right_diagonal_piece = board_current[column_current + 1 * direction_of_move][row_current + 1 * direction_of_move];
            if (right_diagonal_piece->getOccupied() && right_diagonal_piece->getColor() == -1 * direction_of_move){
                position.column = column_current + 1 * direction_of_move;
                position.row    = row_current + 1 * direction_of_move;

                possiblePosition.push_back(position);
            }       
        }
    }
    

    //sprawdzenie możliwości bicia w prawo

    this->setMoves(possiblePosition);

}