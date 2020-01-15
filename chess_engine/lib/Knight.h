/**
 * @file Knight.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Board.h"


class Knight : public Piece{
    public:
    Knight(int column, int row, PieceColor color) :
        Piece (column, row, color){setFigureName("N");};
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard> board, bool initialboard) override;
    double getPositionValue() override ;
};
#endif //KNIGHT_H
