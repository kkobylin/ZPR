//
// Created by krzysiek on 02.12.2019.
//

#define BOOST_TEST_MODULE PawnTest
#include <boost/test/unit_test.hpp>
#include <memory>
#include "lib/Pawn.h"
#include "lib/Piece.h"

BOOST_AUTO_TEST_CASE(PawnTestCase)
{
    std::cout<<"Halko test"<<std::endl;
    PieceColor w = WHITE;
    PieceColor b = BLACK;
    Piece *p = new Pawn(0, 1, w, "Pawn");
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard());
    auto positions = p->getPossibleMoves(board_ptr);

    BOOST_CHECK(positions.size() == 2);
   // BOOST_CHECK_EQUAL((int)x, 9);
   // BOOST_CHECK_CLOSE(x, 9.5f, 0.0001f); // Checks differ no more then 0.0001%
}
