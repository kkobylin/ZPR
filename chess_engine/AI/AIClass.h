//
// Created by Krzysiek on 29/11/2019.
//

#ifndef CHESS_AICLASS_H
#define CHESS_AICLASS_H

#include <memory>
#include <lib/Board.h>

struct MovePacket{
    PieceColor color;
    int value;
    Position src;
    Position dest;
};

class AIClass {
    std::shared_ptr<MovePacket> MiniMaxRoot(int depth, std::shared_ptr<Board> currentBoard, int whosTurn);
    int evaluateBoard(std::shared_ptr<Board> currentBoard, int side);

};


#endif //CHESS_AICLASS_H
