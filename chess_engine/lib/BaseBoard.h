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

class BaseBoard{
    private:

    board_type board;

    Position whiteKing;///< position of white king
    Position blackKing;///< position of black king



    public:
    /**
     * @brief Construct a new Base Board object
     * 
     * @param board vector of strings to generate new board
     */
    BaseBoard(std::vector <std::vector <std::string>> board);
    board_type getBoard(); ///< Return board
    /**
     * @brief 
     * 
     * @param destinationColumn 
     * @param destinationRow 
     * @param sourceColumn From where we move
     * @param sourceRow From where we move
     */
    void updateBoard(int destinationColumn, int destinationRow, int sourceColumn, int sourceRow);

    std::vector <std::vector <std::string>> toString();///< Used to extract board in vector of strings format to create new board
    void printBoardCout(); ///< Prints board in console

    Position getKing(PieceColor kingColor);
    void setKing(Position positionKing, PieceColor kingColor);
    /**
     * @brief Is opponentColor player checked
     * 
     * @param opponentColor Color of player, which is checked
     * @param board Current board
     * @return true 
     * @return false 
     */
    bool isChecking(PieceColor opponentColor, std::shared_ptr<BaseBoard> board);
    /**
     * @brief Is opponentColor player mated
     * 
     * @param opponentColor Color of player, which is mated
     * @param board Current board
     * @return true 
     * @return false 
     */
    bool isCheckMate(PieceColor opponentColor, std::shared_ptr<BaseBoard> board);

};
#endif // BASEBOARD_H