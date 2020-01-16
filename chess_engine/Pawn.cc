#include "lib/Pawn.h"
#include <memory>
#include "AI/PositionValue.h"



std::vector<Position> Pawn::getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation){
    std::vector<Position> possiblePosition;
    Position position = getPosition();

    int directionOfMove = getColor();

    Position dest_square = position + Position{0, directionOfMove};

    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != directionOfMove){
        possiblePosition.push_back(dest_square);
    }
    if(!getMoved()){
        dest_square = position + Position{0, directionOfMove * 2};
        if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != directionOfMove){
            possiblePosition.push_back(dest_square);
        }
    }

    dest_square = position + Position{-1, directionOfMove};
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != directionOfMove){
        possiblePosition.push_back(dest_square);
    }

    dest_square = position + Position{1, directionOfMove};
    if(moveIsInBoard(dest_square) && isMoveValid(dest_square, board) != directionOfMove){
        possiblePosition.push_back(dest_square);
    }



    setMoves(possiblePosition);
    if (originalEvaluation){
        possiblePosition = evaluateCheck(board, false);
        setMoves(possiblePosition);
    }
    return possiblePosition;

}

double Pawn::getPositionValue(){
    PieceColor color = getColor();

    if(color == BLACK)
        return PositionValue::PawnEvalBlack[getRow()][getColumn()];
    else
        return PositionValue::PawnEvalWhite[getRow()][getColumn()];
}