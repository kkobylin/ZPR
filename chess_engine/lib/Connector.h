/**
 * @file Connector.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Bridge between frontend and backend using Boost Python
 * @version 1.0
 * @date 2020-01-15
 */

#ifndef CHESS_ENGINE_CONNECTOR_H
#define CHESS_ENGINE_CONNECTOR_H
#include <string>

class Connector {
public:
    static bool const ifMovePossible(const std::string dest,const std::string src);
    static std::string const checkForWin();
    static std::string const opponentMove();
};


#endif //CHESS_ENGINE_CONNECTOR_H
