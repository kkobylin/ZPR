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
#include <memory>

typedef std::vector <std::vector <std::shared_ptr<Piece>>> board_type;


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
    std::vector <std::vector <std::shared_ptr<Piece>>> board;
    int x;
    int y;
public:
    Board();
    void updateSquare(int, int, std::shared_ptr<Piece>);
    std::vector <std::vector <std::shared_ptr<Piece>>> getBoard();
};
#endif
