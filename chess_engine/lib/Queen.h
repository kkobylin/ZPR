/**
 * @file Queen.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Board.h"

class Queen : public Piece{
public:
    Queen(int column, int row, PieceColor color) :
    Piece (column, row, color){
        setFigureName("Q");
        setRecursive();
        setDirectionOfMove(Position{1,1});
        setDirectionOfMove(Position{0,1});
        setDirectionOfMove(Position{-1,1});
        setDirectionOfMove(Position{1,0});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{-1,-1});
        setDirectionOfMove(Position{-1,0});
        setDirectionOfMove(Position{-1,1});
        };
    
    //std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard> board, bool initialboard);
    double getPositionValue() override ;
};
#endif //QUEEN_H
