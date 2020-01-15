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

    Position whiteKing;
    Position blackKing;



    public:
    BaseBoard(std::vector <std::vector <std::string>>);
    board_type getBoard();
    void updateBoard(int, int, int, int);
    std::vector <std::vector <std::string>> toString();
    void printBoardCout();

    Position getKing(PieceColor kingColor);
    void setKing(Position positionKing, PieceColor kingColor);
    bool isChecking(PieceColor opponentColor, std::shared_ptr<BaseBoard> board);
    bool isCheckMate(PieceColor opponentColor, std::shared_ptr<BaseBoard> board);

};
#endif