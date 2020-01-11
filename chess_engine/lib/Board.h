#ifndef BOARD
#define BOARD
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Empty_square.h"
#include "Square.h"
#include <memory>

typedef std::vector <std::vector <std::shared_ptr<Square>>> board_type;


enum Column {
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8
};

std::vector <std::vector <std::string>> const INITIAL_BOARD = {
{"WR","WN","WB","WQ","WK","WB","WN","WR"},
{"WP","WP","WP","WP","WP","WP","WP","WP"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"BP","BP","BP","BP","BP","BP","BP","BP"},
{"BR","BN","BB","BQ","BK","BB","BN","BR"}

};


class Board{
private:
    static std::shared_ptr<Board> instance;
    board_type board;
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
    Board();
public:
    //void static updateSquare(int, int, std::shared_ptr<Piece>); //todo zeby dzialalo na swoim boardzie
    //std::vector <std::vector <std::shared_ptr<Piece>>> getBoard();

    //todo konstruktor kopiujacy
    //todo update board
    void updateBoard(int,int,int,int);
    static std::shared_ptr<Board> getInstance();
    board_type getBoard();

    bool gogoPowerRangers(std::string ,std::string);

};
#endif
