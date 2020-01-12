#include "lib/BaseBoard.h"
#include "lib/Board.h"
#include <iostream>
#include <memory>

std::shared_ptr<Board> Board::instance = nullptr;

std::shared_ptr<Board> Board::getInstance(){
    if(!instance)
        instance = std::shared_ptr<Board> (new Board());
    return instance;
}

Board::Board() : BaseBoard(INITIAL_BOARD){};
