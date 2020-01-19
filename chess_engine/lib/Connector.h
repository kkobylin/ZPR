/**
 * @file Connector.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Bridge between frontend and backend using Boost Python
 * @version 0.1
 * @date 2020-01-15
 */

#ifndef CHESS_ENGINE_CONNECTOR_H
#define CHESS_ENGINE_CONNECTOR_H
#include <string>

class Connector {
public:
    /**
    * Method checking whether player's move is correct or not
     * @param dest
     * @param src
     * @return true
     * @return false
     */
    static bool const ifMovePossible(const std::string dest,const std::string src);
    /**
     * Method checking whether is it end of game
     * @return string - "none", "draw", "win" or "lose"
     * win - when white player wins
     * lose - when black player wins
     */
    static std::string const checkForWin();
    /**
    * Method use to get opponent move
    * @return move in format "A1-A2"
    */
    static std::string const opponentMove();
};


#endif //CHESS_ENGINE_CONNECTOR_H
