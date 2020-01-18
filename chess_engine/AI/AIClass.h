/**
 * @file AIClass.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Class calculating opponent move, using minmax algorithm
 * @version 1.0
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
    static MovePacket MiniMaxRoot(const int depth,const  PieceColor turn,const std::shared_ptr<BaseBoard> board_obj, double alpha, double beta);

private:
    static double evaluateBoard(const std::shared_ptr<BaseBoard>  board,const PieceColor side);
};


#endif //CHESS_AICLASS_H
