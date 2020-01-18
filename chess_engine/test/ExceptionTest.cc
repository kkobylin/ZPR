/**
 * @file ExceptionTest.cc
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Boost auto test, testing throwing exceptions by functions
 * @version 1.0
 * @date 2020-01-15
 */

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../lib/BaseBoard.h"
#include "../AI/AIClass.h"
#include "../exceptions/IllegalStateException.h"
#include "../exceptions/WrongArgException.h"

BOOST_AUTO_TEST_SUITE(ExceptionTest)

    BOOST_AUTO_TEST_CASE(MinMaxRootException) {
        std::vector<std::vector<std::string>> board = {
                /* 1   2    3    4    5     6   7     8 */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
                {"NN", "WP", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
        };
        std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(board));
        BOOST_CHECK_THROW(AIClass::MiniMaxRoot(1, BLACK, board_ptr, BLACK), IllegalStateException);
    }


    BOOST_AUTO_TEST_CASE(UpdateBoardException) {
        std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
        BOOST_CHECK_THROW(board_ptr->updateBoard(1,1,1,8),WrongArgException);
    }

BOOST_AUTO_TEST_SUITE_END()