#ifndef BISHOP_H
#define BISHOP_H

/**
 * @file Bishop.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class for bishop
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Piece.h"
#include "Board.h"

class Bishop: public Piece{
public:
    Bishop(int column, int row, PieceColor color) :
    Piece (column, row, color){
        setFigureName("B");
        setRecursive();
        setDirectionOfMove(Position{1,1});
        setDirectionOfMove(Position{-1,1});
        setDirectionOfMove(Position{-1,-1});
        setDirectionOfMove(Position{1,-1});
        };
    
    //std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard> board, bool originalEvaluation);
    double getPositionValue() override ;
};
#endif // BISHOP_H
