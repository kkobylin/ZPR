//
// Created by krzysiek on 12.01.2020.
//

#include "lib/Board.h"
#include <iostream>
#include "Connector.h"
#include "AI/AIClass.h"
#include "lib/BaseBoard.h"

using namespace std;

int main(void){
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"WP", "WN", "WK", "WQ", "WR", "WB", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "WP", "BP", "BN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "BB", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "BQ", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "BK", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "BN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"BP", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(case_board));
    board_ptr->printBoardCout();
    auto board2 = BaseBoard(*board_ptr.get());
    board2.printBoardCout();
}