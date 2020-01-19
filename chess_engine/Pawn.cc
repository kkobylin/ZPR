/**
 * @file Pawn.cc
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "lib/Pawn.h"
#include <memory>
#include "AI/PositionValue.h"

Pawn::Pawn(int column, int row, PieceColor color) :
    Piece (column, row, color){
        setFigureName("P");
        setPieceValue(1); //experimental
    }


std::vector<Position> Pawn::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    std::vector<Position> possible_position;
    
    Position position = getPosition();
    int directionOfMove = getColor();

    Position dest_square = position + Position{0, directionOfMove};
    //Move 1 square ahead
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == NONE){
        possible_position.push_back(dest_square);
    }
    //Move 2 squares ahrad
    if(!getMoved()){
        dest_square = position + Position{0, directionOfMove * 2};
        if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == NONE){
            possible_position.push_back(dest_square);
        }
    }
    //Capture left
    dest_square = position + Position{-1, directionOfMove};
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == static_cast<PieceColor>(-1*directionOfMove)){
        possible_position.push_back(dest_square);
    }
    //Caputre right
    dest_square = position + Position{1, directionOfMove};
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == static_cast<PieceColor>(-1*directionOfMove)){
        possible_position.push_back(dest_square);
    }



    setMoves(possible_position);
    if (originalEvaluation){
        possible_position = evaluateCheck(board, false);
        setMoves(possible_position);
    }
    return possible_position;

}

double Pawn::getPositionValue() const{
    PieceColor color = getColor();

    if(color == BLACK)
        return (getPieceValue() * (-1)) + PositionValue::PawnEvalBlack[getRow()][getColumn()] ;
    else
        return (getPieceValue() + PositionValue::PawnEvalWhite[getRow()][getColumn()]);
}