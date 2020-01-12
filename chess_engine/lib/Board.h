#ifndef BOARD
#define BOARD
#include "BaseBoard.h"
#include <memory>


class Board : public BaseBoard{
private:
    static std::shared_ptr<BaseBoard> instance;
    Board& operator=(const Board&) = delete;
    Board();
public:
    //void static updateSquare(int, int, std::shared_ptr<Piece>); //todo zeby dzialalo na swoim boardzie
    //std::vector <std::vector <std::shared_ptr<Piece>>> getBoard();

    //void updateBoard(int,int,int,int);
    static std::shared_ptr<BaseBoard> getInstance();
    //bool gogoPowerRangers(std::string ,std::string);

};
#endif
