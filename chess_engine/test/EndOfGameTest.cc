/**
 * @file EndOfGameTest.cc
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Boost auto test, testing checkForWin method
 * in few cases
 * @version 1.0
 * @date 2020-01-15
 */

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../lib/BaseBoard.h"

BOOST_AUTO_TEST_SUITE(EndOfGameTest)
    BOOST_AUTO_TEST_CASE(WhiteWin) {
        std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
        std::string end_of_game = board_ptr->checkForWin();
        BOOST_CHECK(end_of_game == "none");

        /* scholar`s mate */
        board_ptr->updateBoard(4, 3, 4, 1);
        board_ptr->updateBoard(4, 4, 4, 6);
        board_ptr->updateBoard(2, 3, 5, 0);
        board_ptr->updateBoard(2, 5, 1, 7);
        board_ptr->updateBoard(5, 2, 3, 0);
        board_ptr->updateBoard(5, 6, 5, 2);
        end_of_game = board_ptr->checkForWin();
        BOOST_CHECK(end_of_game == "win");
    }


    BOOST_AUTO_TEST_CASE(BlackWin) {
        std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
        std::string end_of_game = board_ptr->checkForWin();
        BOOST_CHECK(end_of_game == "none");

        /* scholar`s mate */
        board_ptr->updateBoard(4, 3, 4, 1);
        board_ptr->updateBoard(4, 4, 4, 6);
        board_ptr->updateBoard(0, 2, 0, 1);
        board_ptr->updateBoard(2, 4, 5, 7);
        board_ptr->updateBoard(1, 2, 1, 1);
        board_ptr->updateBoard(7, 3, 3, 7);
        board_ptr->updateBoard(2, 2, 2, 1);
        board_ptr->updateBoard(5, 1, 7, 3);
        end_of_game = board_ptr->checkForWin();
        BOOST_CHECK(end_of_game == "lose");
    }

BOOST_AUTO_TEST_SUITE_END()