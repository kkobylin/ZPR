#include "lib/Board.h"
#include <iostream>

int main(void){
    //std::cout << "tu";
    Board board {};
    Position pos {2,1};


     for (auto b : board.getBoard())
        for (auto a : b)
            ;//a->move(pos,board);
    board_type x = board.getBoard();
    x[1][1]->move(pos,board);


}

