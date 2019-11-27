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

typedef std::vector <std::vector <Piece *>> board_type;


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
{"BR","BN","BB","BQ","BK","BB","BN","BR"},
{"BP","BP","BP","BP","BP","BP","BP","BP"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"NN","NN","NN","NN","NN","NN","NN","NN"},
{"WP","WP","WP","WP","WP","WP","WP","WP"},
{"WR","WN","WB","WQ","WK","WB","WN","WR"}
};


class Board{
private:
    std::vector <std::vector <Piece *>> board;
    int x;
    int y;
public:
    Board();
    void updateSquare(int, int, Piece *);
    std::vector <std::vector <Piece *>> getBoard();
};
#endif
