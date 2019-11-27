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
    std::vector<std::vector <Piece *>> board_current = board.getBoard();
    std::vector<Position> possiblePosition;
    Position position;

    //sprawdzenie możliwości ruchu
    if(!board_current[column_current][row_current + 1]->getOccupied()){
        position.column = column_current;
        position.row    = row_current + 1;

        possiblePosition.push_back(position);
    }
    if(!this->getMoved())
        if(!board_current[column_current][row_current + 2]->getOccupied()){
            position.column = column_current;
            position.row    = row_current + 2;

            possiblePosition.push_back(position);
        }
    //sprawdzenie możliwości bicia



    this->setMoves(possiblePosition);

};