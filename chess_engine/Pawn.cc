#include "lib/Pawn.h"
#include <memory>
#include "AI/PositionValue.h"



std::vector<Position> Pawn::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    std::vector<Position> possible_position;
    Position position = getPosition();

    int directionOfMove = getColor();
    //std::cout << directionOfMove << std::endl;

    Position dest_square = position + Position{0, directionOfMove};

    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == NONE){
        possible_position.push_back(dest_square);
    }
    if(!getMoved()){
        dest_square = position + Position{0, directionOfMove * 2};
        if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == NONE){
            possible_position.push_back(dest_square);
        }
    }

    dest_square = position + Position{-1, directionOfMove};
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) == static_cast<PieceColor>(-1*directionOfMove)){
        possible_position.push_back(dest_square);
    }

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

double Pawn::getPositionValue(){
    PieceColor color = getColor();

    if(color == BLACK)
        return PositionValue::PawnEvalBlack[getRow()][getColumn()];
    else
        return PositionValue::PawnEvalWhite[getRow()][getColumn()];
}