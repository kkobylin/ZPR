/**
 * @file AIClass.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Class calculating opponent move, using minmax algorithm
 * @version 0.1
 * @date 2020-01-15
 */
#ifndef CHESS_AICLASS_H
#define CHESS_AICLASS_H

#include <memory>
#include <vector>
#include "../lib/Square.h"


struct MovePacket{
    int src_row;
    int src_col;
    int dest_row;
    int dest_col;
    double score;
};

typedef std::vector <std::vector <std::shared_ptr<Square>>> board_type;

class AIClass {
public:
    /**
     * @brief static method returning result of minmax algorithm
     * @param depth - depth of minmax algorithm, 1 is minimum
     * @param turn
     * @param board_obj
     * @param alpha
     * @param beta
     * @return struct with move coordinates and score
     */
    static MovePacket MiniMaxRoot(const int depth,const  PieceColor turn,const std::shared_ptr<BaseBoard> board_obj, double alpha, double beta);

private:
    /**
     * @brief method evaluating board by getting position value of each piece on the board
     * @param board
     * @return score
     */
    static double evaluateBoard(const std::shared_ptr<BaseBoard>  board);
};


#endif //CHESS_AICLASS_H
