/**
 * @file Board.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class holding main board, constructed as Singleton
 * @version 0.1
 * @date 2020-01-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BOARD_H
#define BOARD_H
#include "BaseBoard.h"
#include <memory>


class Board : public BaseBoard{
private:
    static std::shared_ptr<Board> instance;
    Board& operator=(const Board&) = delete;
    Board();
public:
    static std::shared_ptr<Board> getInstance();

};
#endif //BOARD_H
