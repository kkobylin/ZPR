//
// Created by Krzysiek on 29/11/2019.
//

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
    static MovePacket MiniMaxRoot(int depth, PieceColor turn, std::shared_ptr<BaseBoard> board_obj, PieceColor side);

private:
    static double evaluateBoard(std::shared_ptr<BaseBoard>  board, PieceColor side);
};


#endif //CHESS_AICLASS_H
