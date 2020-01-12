#ifndef BASEBOARD
#define BASEBOARD


#include "Square.h"
#include <vector>
#include <iostream>
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

class BaseBoard{
    private:
    board_type board;

    public:
    BaseBoard();
    board_type getBoard();
    //BaseBoard(const BaseBoard&);
    void updateBoard(int,int,int,int);

};


#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Empty_square.h"

#endif