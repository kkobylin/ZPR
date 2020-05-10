/**
 * @file FigureLogicTest.cc
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Boost auto test, testing possible moves of each Piece
 * in many cases
 * @details For each piece there are tested every generalized cases
 * including such when piece should defend his king from checking or
 * avoid his king from checking
 * @version 1.0
 * @date 2020-01-15
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ChessTest

#include <boost/test/included/unit_test.hpp>
#include "../lib/Pawn.h"
#include "../lib/Bishop.h"
#include <memory>
#include "../lib/Piece.h"
#include "../lib/BaseBoard.h"
#include "../lib/Knight.h"
#include "../lib/Queen.h"
#include "../lib/Rook.h"
#include "../lib/King.h"
#include <vector>
#include <algorithm>

/**
 * Function comparing vector of correct possible positions
 * with positions from GetPossibleMoves method
 */
void compareVectors(std::vector<Position> pos,std::vector<std::string> correct_positions) {
    std::vector <std::string> positions;

    for(auto p : pos){
        positions.push_back(p.toString());
    }

    std::sort(positions.begin(), positions.end());
    std::sort(correct_positions.begin(), correct_positions.end());
    BOOST_CHECK(positions == correct_positions);
}

BOOST_AUTO_TEST_CASE(PawnCase) {
    /* 1st case - beginning of the game */
    Piece *p = new Pawn(0, 1, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));

    auto pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);

    std::vector<std::string> correct_positions;
    correct_positions.emplace_back("02");
    correct_positions.emplace_back("03");

    compareVectors(pos, correct_positions);

    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "WP", "BP", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(2, 3, WHITE);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.empty());

    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "WP", "NN", "BP", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(2, 6, BLACK);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correct_positions.clear();
    correct_positions.emplace_back("25");

    compareVectors(pos, correct_positions);

    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "WP", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "BP", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "WP", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(3, 5, BLACK);
    p->setMoved(true);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);
    correct_positions.clear();
    correct_positions.emplace_back("24");
    correct_positions.emplace_back("34");
    correct_positions.emplace_back("44");

    compareVectors(pos, correct_positions);

    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "WP", "BP", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "BP", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(0, 2, WHITE);
    p->setMoved(true);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correct_positions.clear();
    correct_positions.emplace_back("13");

    compareVectors(pos, correct_positions);

    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "WP", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "BP", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "WP", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(1, 6, BLACK);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 4);
    correct_positions.clear();
    correct_positions.emplace_back("05");
    correct_positions.emplace_back("15");
    correct_positions.emplace_back("14");
    correct_positions.emplace_back("25");

    compareVectors(pos, correct_positions);

    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "WP", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "WP"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "WP", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(1, 7, WHITE);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.empty());
    /* 7th  case - King Defending - avoid King from check*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "BP", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "WK", "WP", "NN", "NN", "NN", "BR"}, /* D */
            {"NN", "NN", "NN", "NN", "BP", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(3, 3, WHITE);
    p->setMoved(true);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);

    correct_positions.clear();
    correct_positions.emplace_back("34");

    compareVectors(pos, correct_positions);

    /* 8th  case - King Defending - stop king checking*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "BP", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "WP", "BQ", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "BB", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "WK", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(2, 2, WHITE);
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);

    correct_positions.clear();
    correct_positions.emplace_back("33");

    compareVectors(pos, correct_positions);
}

BOOST_AUTO_TEST_CASE(BishopCase) {

    /* 1st case - beginning of the game */
    Piece *b = new Bishop(2, 0, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    auto pos = b->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.empty());

    /* 2nd  case */
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "BB", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(3, 3, BLACK);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 13);

    /* 3rd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"WB", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(7, 0, WHITE);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 7);

    /* 4th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"WR", "NN", "BR", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "WB", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"WR", "NN", "BR", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(1, 1, WHITE);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);

    std::vector<std::string> correctPositions;
    correctPositions.clear();
    correctPositions.emplace_back("02");
    correctPositions.emplace_back("22");

    compareVectors(pos, correctPositions);

    /* 5th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"BR", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "WR", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "WR"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "WB", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "BR", "NN", "WR"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(6, 6, WHITE);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 5);

    /* 6th  case - King Defending - avoid King from check*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "BK", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "BB", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "WQ", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(2, 3, BLACK);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correctPositions.clear();
    correctPositions.emplace_back("34");
    compareVectors(pos, correctPositions);

    /* 6th  case - King Defending - stop king checking*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "WK", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "WB", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "BB", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(3, 2, WHITE);
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correctPositions.clear();
    correctPositions.emplace_back("23");

    compareVectors(pos, correctPositions);
}
BOOST_AUTO_TEST_CASE(KnightCase) {
    /* 1st case - beginning of the game */
    Piece *n = new Knight(1, 0, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    auto pos = n->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 2);

    /* 2nd  case */
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "WP", "BP", "WP", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "BP", "BN", "BP", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "WP", "BP", "WP", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete n;
    n = new Knight(3, 3, BLACK);
    pos = n->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 8);

    /* 3rd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"BR", "NN", "BN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "BR", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "WN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete n;
    n = new Knight(7, 1, WHITE);
    pos = n->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);

    std::vector<std::string> correctPositions;
    correctPositions.clear();
    correctPositions.emplace_back("50");
    correctPositions.emplace_back("52");
    correctPositions.emplace_back("63");

    compareVectors(pos, correctPositions);
}
BOOST_AUTO_TEST_CASE(QueenCase) {
    /* 1st case - beginning of the game */
    Piece *q = new Queen(3, 0, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    auto pos = q->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.empty());

    /* 2nd case */
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "BP", "BP", "BP", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "BP", "WQ", "BP", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "BP", "BP", "BP", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete q;
    q = new Queen(3, 3, WHITE);
    pos = q->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 8);

    /* 3rd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "BP", "NN", "BQ", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "BP", "NN", "BP", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete q;
    q = new Queen(0, 6, BLACK);
    pos = q->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 5);
}

BOOST_AUTO_TEST_CASE(RookCase) {
    /* 1st case - beginning of the game */
    Piece *r = new Rook(0, 0, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    auto pos = r->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.empty());

    /* 2nd case */
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "BR", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(3, 3, BLACK);
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 14);

    /* 3rd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* B */
            {"WR", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"BR", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"WR", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(3, 0, BLACK);
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 9);

    /* 4th case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN", "NN", "NN", "NN", "NN", "NN", "WP", "WR"}, /* A */
            {"NN", "NN", "NN", "NN", "NN", "NN", "BR", "WP"}, /* B */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* C */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* D */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* E */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* F */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}, /* G */
            {"NN", "NN", "NN", "NN", "NN", "NN", "NN", "NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(0, 7, WHITE);
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.empty());
}

BOOST_AUTO_TEST_CASE(KingCase)
{
    /* 1st case - beginning of the game */
    Piece *k = new King(4, 0, WHITE);
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    auto pos = k->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.empty());

    /* 2nd case*/
    std::vector<std::vector<std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","WK"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete k;
    k = new King(0, 7, WHITE);
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);

    /* 3rd case*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","BR","NN","BR","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","WK","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete k;
    k = new King(3, 3, WHITE);
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);

    /* 4th case*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","BR","NN","BR","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","BR","NN"}, /* C */
            {"NN","NN","NN","WK","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","BR","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete k;
    k = new King(3, 3, WHITE);
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.empty());

    /* 5th case*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","BP","WP","BP","NN","NN","NN"}, /* G */
            {"NN","NN","NN","BK","NN","NN","NN","WR"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete k;
    k = new King(7, 3, BLACK);
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    std::vector<std::string> correctPositions;
    correctPositions.clear();
    correctPositions.emplace_back("63");

    compareVectors(pos, correctPositions);

    /* 6th case*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","BQ","BB","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","WK","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete k;
    k = new King(4, 3, WHITE);
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);

    correctPositions.clear();
    correctPositions.emplace_back("32");
    correctPositions.emplace_back("53");

    compareVectors(pos, correctPositions);

}