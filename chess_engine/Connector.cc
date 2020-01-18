/**
 * @file Connector.cc
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Bridge between frontend and backend using Boost Python
 * @version 1.0
 * @date 2020-01-15
 */

#include "Connector.h"
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "lib/Board.h"
#include <memory>
#include <string>
#include "AI/AIClass.h"
#include "lib/BaseBoard.h"
#include "exceptions/WrongArgException.h"

/**
 * Method use by frontend to check whether white player's move
 * is correct or not
 * @param dest - destination of piece
 * @param src - source, prior position of piece
 * @return bool - move correct or not
 */
bool const Connector::ifMovePossible(std::string dest, std::string src){

    if(dest == "offboard")
        return false;

    std::shared_ptr<BaseBoard> board_instance = Board::getInstance();
    board_type board = board_instance->getBoard();

    /**
     * Convert columns from A to H to 0-7
     */
    int src_col;
    int dest_col;
    switch (src[0]){
        case 'a':
            src_col = 0;
            break;
        case 'b':
            src_col = 1;
            break;
        case 'c':
            src_col = 2;
            break;
        case 'd':
            src_col = 3;
            break;
        case 'e':
            src_col = 4;
            break;
        case 'f':
            src_col = 5;
            break;
        case 'g':
            src_col = 6;
            break;
        case 'h':
            src_col = 7;
            break;
        default:
            return false;
    }

    switch (dest[0]){
        case 'a':
            dest_col = 0;
            break;
        case 'b':
            dest_col = 1;
            break;
        case 'c':
            dest_col = 2;
            break;
        case 'd':
            dest_col = 3;
            break;
        case 'e':
            dest_col = 4;
            break;
        case 'f':
            dest_col = 5;
            break;
        case 'g':
            dest_col = 6;
            break;
        case 'h':
            dest_col = 7;
            break;
        default:
            return false;
    }

    /**
     * Convert rows from 1 to 8 to 0-7
     * */
    int src_row;
    int dest_row;
    try {
        src_row = std::stoi(src.substr(1, 1));
        src_row--;
        dest_row = std::stoi(dest.substr(1, 1));
        dest_row--;
    }
    catch (std::exception& e){
        return false;
    }

    std::vector<Position> possible_positions = board[src_col][src_row]->getPiece()->getPossibleMoves(board_instance);

    for(Position p : possible_positions){
        if(p.column == dest_col && p.row == dest_row){
            try {
                board_instance->updateBoard(dest_col, dest_row, src_col, src_row);
            }
            catch(WrongArgException& e){
                return false;
            }
            return true;
        }
    }

    return false;
}
/**
 * Method use by frontend after each move to check
 * if it is end of the game
 * @return string - "none", "draw", "win" or "lose"
 * win - when white player wins
 * lose - when black player wins
 */
std::string const Connector::checkForWin() {
    auto board = Board::getInstance();
    return board->checkForWin();
}

/**
 * Method use by frontend to get opponent move
 * @return move in format "A1-A2"
 */
std::string const Connector::opponentMove(){
        /* Format e2-e4 */
    auto board = Board::getInstance();
    std::shared_ptr<BaseBoard> min_max_board(new BaseBoard(board->toString()));

    MovePacket move_packet;
    try {
        move_packet = AIClass::MiniMaxRoot(3, BLACK, min_max_board, std::numeric_limits<double>::max()*-1, std::numeric_limits<double>::max());
        board->updateBoard(move_packet.dest_col, move_packet.dest_row, move_packet.src_col, move_packet.src_row);
    }
    catch(std::exception& e){
        return "00-00";
    }

    std::string chessColumnConvert[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

    std::string src_row = std::to_string(++move_packet.src_row);
    std::string src_col = chessColumnConvert[move_packet.src_col];
    std::string dest_row = std::to_string(++move_packet.dest_row);
    std::string dest_col = chessColumnConvert[move_packet.dest_col];

    return src_col + src_row + '-' + dest_col + dest_row;
}

BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible);
                def("checkForWin", Connector::checkForWin);
                def("opponentMove", Connector::opponentMove);
        }