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
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    AIClass::MiniMaxRoot(2, BLACK, board_ptr, BLACK);
    Connector::checkForWin();
}