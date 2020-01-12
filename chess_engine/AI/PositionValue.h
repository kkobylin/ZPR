//
// Created by Krzysiek on 29/11/2019.
//

#ifndef CHESS_POSITIONVALUE_H
#define CHESS_POSITIONVALUE_H

class PositionValue {
public:
    static const double KingEvalWhite [8][8];
    static const double KingEvalBlack [8][8];
    static const double QueenEval [8][8];
    static const double RookEvalWhite [8][8];
    static const double RookEvalBlack [8][8];
    static const double BishopEvalWhite [8][8];
    static const double BishopEvalBlack [8][8];
    static const double KnightEval [8][8];
    static const double PawnEvalWhite [8][8];
    static const double PawnEvalBlack [8][8];
};
#endif //CHESS_POSITIONVALUE_H
