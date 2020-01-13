//
// Created by krzysiek on 11.01.2020.
//

#include "PositionValue.h"

const double PositionValue::KingEvalWhite [8][8] =
        {
                {20, 30, 10,  0,  0, 10, 30, 20},
                {20, 20,  0,  0,  0,  0, 20, 20},
                {-10,-20,-20,-20,-20,-20,-20,-10},
                {-20,-30,-30,-40,-40,-30,-30,-20},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30}
        };

const double PositionValue::KingEvalBlack [8][8] =
        {
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-30,-40,-40,-50,-50,-40,-40,-30},
                {-20,-30,-30,-40,-40,-30,-30,-20},
                {-10,-20,-20,-20,-20,-20,-20,-10},
                {20, 20,  0,  0,  0,  0, 20, 20},
                {20, 30, 10,  0,  0, 10, 30, 20}
        };

const double PositionValue::QueenEval [8][8] =
        {
                {-20,-10,-10, -5, -5,-10,-10,-20},
                {-10,  0,  0,  0,  0,  0,  0,-10},
                {-10,  0,  5,  5,  5,  5,  0,-10},
                {-5,  0,  5,  5,  5,  5,  0, -5},
                {0,  0,  5,  5,  5,  5,  0, -5},
                {-10,  5,  5,  5,  5,  5,  0,-10},
                {-10,  0,  5,  0,  0,  0,  0,-10},
                {-20,-10,-10, -5, -5,-10,-10,-20}
        };

const double PositionValue::RookEvalWhite [8][8] =
        {
                {0,  0,  0,  5,  5,  0,  0,  0},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {5, 10, 10, 10, 10, 10, 10,  5},
                {0,  0,  0,  0,  0,  0,  0,  0}

        };

const double PositionValue::RookEvalBlack [8][8] =
        {
                {0,  0,  0,  0,  0,  0,  0,  0},
                {5, 10, 10, 10, 10, 10, 10,  5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {-5,  0,  0,  0,  0,  0,  0, -5},
                {0,  0,  0,  5,  5,  0,  0,  0}
        };

const double PositionValue::BishopEvalWhite [8][8] =
        {
                {-20,-10,-10,-10,-10,-10,-10,-20},
                {-10,  5,  0,  0,  0,  0,  5,-10},
                {-10, 10, 10, 10, 10, 10, 10,-10},
                {-10,  0, 10, 10, 10, 10,  0,-10},
                {-10,  5,  5, 10, 10,  5,  5,-10},
                {-10,  0,  5, 10, 10,  5,  0,-10},
                {-10,  0,  0,  0,  0,  0,  0,-10},
                {-20,-10,-10,-10,-10,-10,-10,-20}
        };

const double PositionValue::BishopEvalBlack [8][8] =
        {
                {-20,-10,-10,-10,-10,-10,-10,-20},
                {-10,  0,  0,  0,  0,  0,  0,-10},
                {-10,  0,  5, 10, 10,  5,  0,-10},
                {-10,  5,  5, 10, 10,  5,  5,-10},
                {-10,  0, 10, 10, 10, 10,  0,-10},
                {-10, 10, 10, 10, 10, 10, 10,-10},
                {-10,  5,  0,  0,  0,  0,  5,-10},
                {-20,-10,-10,-10,-10,-10,-10,-20}
        };

const double PositionValue::KnightEval [8][8] =
        {
                {-50,-40,-30,-30,-30,-30,-40,-50},
                {-40,-20,  0,  5,  5,  0,-20,-40},
                {-30,  5, 10, 15, 15, 10,  5,-30},
                {-30,  5, 15, 20, 20, 15,  5,-30},
                {-30,  0, 15, 20, 20, 15,  0,-30},
                {-30,  0, 10, 15, 15, 10,  0,-30},
                {-40,-20,  0,  0,  0,  0,-20,-40},
                {-50,-40,-30,-30,-30,-30,-40,-50}
        };

const double PositionValue::PawnEvalWhite [8][8] =
        {
                            /*A B C D E F G H*/
                /* 1 */   {0,  0,  0,  0,  0,  0,  0,  0},
                /* 2 */   {5, 10, 10,-20,-20, 10, 10,  5},
                /* 3 */    {5, -5,-10,  0,  0,-10, -5,  5},
                /* 4 */   {0,  0,  0, 20, 20,  0,  0,  0},
                /* 5 */   {5,  5, 10, 25, 25, 10,  5,  5},
                /* 6 */  {10, 10, 20, 30, 30, 20, 10, 10},
                /* 7 */  {50, 50, 50, 50, 50, 50, 50, 50},
                /* 8 */  {0,  0,  0,  0,  0,  0,  0,  0}
        };

const double PositionValue::PawnEvalBlack [8][8] =
        {
                {0,  0,  0,  0,  0,  0,  0,  0},
                {-50, -50, -50, -50, -50, -50, -50, -50},
                {-10, -10, -20, -30, -30, -20, -10, -10},
                {-5,  -5, -10, -25, -25, -10,  -5,  -5},
                {0,  0,  0, -20, -20,  0,  0,  0},
                {-5, 5,10,  0,  0,10, 5,  -5},
                {-5, -10, -10,20,20, -10, -10,  -5},
                {0,  0,  0,  0,  0,  0,  0,  0}
        };
