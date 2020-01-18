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

class BaseBoard : public std::enable_shared_from_this<BaseBoard>{
    private:
    board_type board;

    Position white_king;
    Position black_king;

    public:
    BaseBoard(const std::vector <std::vector <std::string>>);
    BaseBoard(const BaseBoard &base_board);
    board_type getBoard() const;
    void updateBoard(const int dest_col,const int dest_row,const int src_col,const int src_row);
    std::vector <std::vector <std::string>> toString() const;
    //todo usunac
    void printBoardCout();

    Position getKing(const PieceColor king_color) const;
    void setKing(const Position position_king,const PieceColor king_color);
    bool isChecking(const PieceColor opponent_color);
    std::string checkForWin();

};
#endif