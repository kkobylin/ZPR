//
// Created by krzysiek on 01.12.2019.
//

#ifndef CHESS_ENGINE_CONNECTOR_H
#define CHESS_ENGINE_CONNECTOR_H
#include <string>

class Connector {



public:
    static bool const ifMovePossible(std::string dest, std::string src);
    static std::string const checkForWin();
    static std::string const opponentMove();
};


#endif //CHESS_ENGINE_CONNECTOR_H
