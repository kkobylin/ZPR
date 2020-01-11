//
// Created by Krzysiek on 29/11/2019.
//

#ifndef CHESS_AICLASS_H
#define CHESS_AICLASS_H

#include <memory>
#include <lib/Board.h>

struct MovePacket{
    int src;
    int dest;
};

typedef std::vector <std::vector <std::shared_ptr<Piece>>> board_type;

class AIClass {
public:
    MovePacket MiniMaxRoot(int depth, PieceColor turn);

private:
    double evaluateBoard(board_type board);
};


#endif //CHESS_AICLASS_H
