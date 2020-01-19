/**
 * @file Board.cc
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
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
