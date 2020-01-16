/**
 * @file BaseBoard.h
 * @author Marcin Michalski (marmichalski97@gmail.com)
 * @brief Class holding informations about pieces, used to be an auxiliary class to generate temporary boards
 * @version 0.1
 * @date 2020-01-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef BASEBOARD_H
#define BASEBOARD_H


#include "Square.h"
#include <vector>
#include <iostream>
#include <memory>

/**
 * @brief 
 * 
 */
typedef std::vector <std::vector <std::shared_ptr<Square>>> board_type;

/**
 * @brief vector used to initialize starting boards
 * 
 */
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
    BaseBoard(std::vector <std::vector <std::string>>);
    board_type getBoard();
    void updateBoard(int dest_col, int dest_row, int src_col, int src_row);
    std::vector <std::vector <std::string>> toString();
    void printBoardCout();

    Position getKing(PieceColor king_color);
    void setKing(Position position_king, PieceColor king_color);
    bool isChecking(PieceColor opponent_color);
    std::string checkForWin();

};
#endif // BASEBOARD_H