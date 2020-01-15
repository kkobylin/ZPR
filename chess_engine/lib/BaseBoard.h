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
{"WR","WP","NN","NN","NN","NN","BP","BR"},
{"WN","WP","NN","NN","NN","NN","BP","BN"},
{"WB","WP","NN","NN","NN","NN","BP","BB"},
{"WQ","WP","NN","NN","NN","NN","BP","BQ"},
{"WK","WP","NN","NN","NN","NN","BP","BK"},
{"WB","WP","NN","NN","NN","NN","BP","BB"},
{"WN","WP","NN","NN","NN","NN","BP","BN"},
{"WR","WP","NN","NN","NN","NN","BP","BR"}

};

class BaseBoard{
    private:
    board_type board;

    public:
    BaseBoard(std::vector <std::vector <std::string>>);
    board_type getBoard();
    void updateBoard(int dest_col, int dest_row, int src_col, int src_row);
    std::vector <std::vector <std::string>> toString();
    void printBoardCout();

};
#endif