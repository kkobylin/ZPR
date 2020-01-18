/**
 * @file PositionValue.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Class holding information how valuable is each piece on each position,
 * used in minmax algorithm
 * @version 1.0
 * @date 2020-01-15
 */

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
