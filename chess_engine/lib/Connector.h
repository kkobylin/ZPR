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
    /**
     * @brief method connecting cpp and python, given params check if move possible
     * 
     * @param dest destination Square
     * @param src source Square
     * @return true 
     * @return false 
     */
    static bool const ifMovePossible(const std::string dest,const std::string src);
    static std::string const checkForWin();
    static std::string const opponentMove();
};


#endif //CHESS_ENGINE_CONNECTOR_H
