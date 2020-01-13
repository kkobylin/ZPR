#ifndef BOARD
#define BOARD
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
#endif
