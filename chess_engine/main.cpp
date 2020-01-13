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
    //std::cout << "tu";
//    Board board {};
//    Position pos {1,2};
//
//
//    for (auto b : board.getBoard())
//        for (auto a : b)
//            std::cout << *a;
//    board_type x = board.getBoard();
//    x[1][1]->move(pos,board);

    std::vector <std::vector <std::string>> const example_board = {
            {"NN","NN","NN","NN","NN","NN","NN","NN"},
            {"NN","NN","NN","WP","NN","NN","NN","NN"},
            {"NN","NN","NN","NN","BP","NN","NN","NN"},
            {"NN","NN","NN","WP","NN","NN","NN","NN"},
            {"NN","NN","NN","NN","NN","NN","NN","NN"},
            {"NN","NN","NN","NN","NN","NN","NN","NN"},
            {"NN","NN","NN","NN","NN","NN","NN","NN"},
            {"NN","NN","NN","NN","NN","NN","NN","NN"}
    };

    std::string chessColumnConvert[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(example_board));
    MovePacket mp = AIClass::MiniMaxRoot(2, BLACK, board_ptr, BLACK);
    //std::string result = Connector::opponentMove();
    std::string src_row = std::to_string(++mp.src_row);
    std::string src_col = chessColumnConvert[mp.src_col];
    std::string dest_row = std::to_string(++mp.dest_row);
    std::string dest_col = chessColumnConvert[mp.dest_col];
    cout<< src_col + src_row + '-' + dest_col + dest_row<<endl;
}