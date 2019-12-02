#include "lib/Board.h"
#include "Connector.h"
#include <iostream>

int main(void){
    //std::cout << "tu";
//    Board board {};
//    Position pos {1,2};
//
//
//     for (auto b : board.getBoard())
//        for (auto a : b)
//            std::cout << *a;
//    board_type x = board.getBoard();
//    x[1][1]->move(pos,board);
    Connector *c = new Connector();
    bool m = c->ifMovePossible("d2", "d4");
    std::cout<<m<<std::endl;
}

