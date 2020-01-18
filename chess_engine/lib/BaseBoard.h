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
    BaseBoard(const std::vector <std::vector <std::string>>);
    BaseBoard(const BaseBoard &base_board);
    board_type getBoard() const;
    void updateBoard(const int dest_col,const int dest_row,const int src_col,const int src_row);
    std::vector <std::vector <std::string>> toString() const;

    Position getKing(const PieceColor king_color) const;
    void setKing(const Position position_king,const PieceColor king_color);
    bool isChecking(const PieceColor opponent_color);
    std::string checkForWin();
    void const printBoardCout();

};
#endif // BASEBOARD_H