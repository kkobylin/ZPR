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
#include "../exceptions/WrongArgException.h"

BOOST_AUTO_TEST_SUITE(ExceptionTest)

    BOOST_AUTO_TEST_CASE(UpdateBoardException) {
        std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
        BOOST_CHECK_THROW(board_ptr->updateBoard(1,1,1,8),WrongArgException);
    }

BOOST_AUTO_TEST_SUITE_END()