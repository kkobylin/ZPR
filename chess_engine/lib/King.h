/**
 * @file King.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Board.h"

class King : public Piece{
private:
    bool castled = false;
    bool checked = false;

public:
    King(int column, int row, PieceColor color) :
        Piece (column, row, color){setFigureName("K");};
    
    std::vector<Position> getPossibleMoves(std::shared_ptr<BaseBoard> board, bool initialboard) override;
    double getPositionValue() override ;

    bool getCastled();
    bool getChecked();

    void setCastled(bool castled);
    void setChecked(bool checked);
};
#endif //KING_H
