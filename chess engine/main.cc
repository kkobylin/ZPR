#include "lib/Board.h"
#include <iostream>

int main(void){
    std::cout << "tu";
    Board board {};

board.getBoard();
     for (auto b : board.getBoard())
        for (auto a : b)
            std::cout << a << std::endl;

}

