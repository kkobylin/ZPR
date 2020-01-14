//
// Created by krzysiek on 02.12.2019.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ChessTest
#include <boost/test/included/unit_test.hpp>

#include <boost/test/unit_test.hpp>

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

void compareVectors(std::vector<Position> pos ,std::vector<std::string> correctPositions){
    std::vector <std::string> positions;

    for(auto p : pos){
        positions.push_back(p.toString());
    }

    std::sort(positions.begin(), positions.end());
    std::sort(correctPositions.begin(), correctPositions.end());
    BOOST_CHECK(positions == correctPositions);
}

BOOST_AUTO_TEST_CASE(PawnTestCase)
{
    /* 1st case - beginning of the game */
    Piece *p = new Pawn(0, 1, WHITE, "P");
    std::shared_ptr<BaseBoard> board_ptr(new BaseBoard(INITIAL_BOARD));

    auto pos = p->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 2);

    std::vector<std::string> correctPositions;
    correctPositions.push_back("02");
    correctPositions.push_back("03");

    compareVectors(pos, correctPositions);

    /* 2nd case - figure in front of pawn, no other figures nearby */
    std::vector <std::vector <std::string>> case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","WP","BP","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(2, 3, WHITE, "P");
    pos = p->getPossibleMoves(board_ptr);
    //todo chce zbic piona
    //BOOST_CHECK(pos.size() == 0);

    /* 3rd case - black pawn on the beginning position, figure 2 fields in front of*/
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","WP","NN","BP","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(2, 6, BLACK, "P");
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correctPositions.clear();
    correctPositions.push_back("25");

    compareVectors(pos, correctPositions);

    /* 4th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","WP","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","BP","NN","NN"}, /* D */
            {"NN","NN","NN","NN","WP","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(3, 5, BLACK, "P");
    p->setMoved();
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);
    correctPositions.clear();
    correctPositions.push_back("24");
    correctPositions.push_back("34");
    correctPositions.push_back("44");

    compareVectors(pos, correctPositions);

    /* 5th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","WP","BP","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","BP","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(0, 2, WHITE, "P");
    p->setMoved();
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 1);
    correctPositions.clear();
    correctPositions.push_back("13");

    compareVectors(pos, correctPositions);

    /* 6th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","WP","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","BP","NN"}, /* B */
            {"NN","NN","NN","NN","NN","WP","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(1, 6, BLACK, "P");
    pos = p->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 4);
    correctPositions.clear();
    correctPositions.push_back("05");
    correctPositions.push_back("15");
    correctPositions.push_back("14");
    correctPositions.push_back("25");

    compareVectors(pos, correctPositions);

    /* 7th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","WP","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","WP"}, /* B */
            {"NN","NN","NN","NN","NN","WP","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete p;
    p = new Pawn(1, 7, WHITE, "P");
    //pos = p->getPossibleMoves(board_ptr);
    //todo nie dziala test na get Possible moves
    //BOOST_CHECK(pos.size() == 0);

/* --------------------------------------------------------------- Bishop -----------------------------------------------------------------------------------------------*/

    /* 1st case - beginning of the game */
    Piece *b = new Bishop(2, 0, WHITE, "B");
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    pos = b->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 0);

    /* 2nd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","BB","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(3, 3, BLACK, "B");
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 13);

    /* 3rd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"WB","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(7, 0, WHITE, "B");
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 7);

    /* 4th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"WR","NN","BR","NN","NN","NN","NN","NN"}, /* A */
            {"NN","WB","NN","NN","NN","NN","NN","NN"}, /* B */
            {"WR","NN","BR","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(1, 1, WHITE, "B");
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);

    correctPositions.clear();
    correctPositions.push_back("02");
    correctPositions.push_back("22");

    compareVectors(pos, correctPositions);

    /* 5th  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"BR","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","WR","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","WR"}, /* F */
            {"NN","NN","NN","NN","NN","NN","WB","NN"}, /* G */
            {"NN","NN","NN","NN","NN","BR","NN","WR"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete b;
    b = new Bishop(6, 6, WHITE, "B");
    pos = b->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 5);

/* --------------------------------------------------------------- Knight -----------------------------------------------------------------------------------------------*/
    /* 1st case - beginning of the game */
    Piece *n = new Knight(1, 0, WHITE, "N");
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    pos = n->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 2);

    /* 2nd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","WP","BP","WP","NN","NN","NN"}, /* C */
            {"NN","NN","BP","BN","BP","NN","NN","NN"}, /* D */
            {"NN","NN","WP","BP","WP","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete n;
    n = new Knight(3, 3, BLACK, "N");
    pos = n->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 8);

    /* 3rd  case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"BR","NN","BN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","BR","NN","NN","NN","NN"}, /* G */
            {"NN","WN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete n;
    n = new Knight(7, 1, WHITE, "N");
    pos = n->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);

    correctPositions.clear();
    correctPositions.push_back("50");
    correctPositions.push_back("52");
    correctPositions.push_back("63");

    compareVectors(pos, correctPositions);

    /* --------------------------------------------------------------- Queen -----------------------------------------------------------------------------------------------*/
    /* 1st case - beginning of the game */
    Piece *q = new Queen(3, 0, WHITE, "Q");
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    pos = q->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 0);

    /* 2nd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","BP","BP","BP","NN","NN","NN"}, /* C */
            {"NN","NN","BP","WQ","BP","NN","NN","NN"}, /* D */
            {"NN","NN","BP","BP","BP","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete q;
    q = new Queen(3, 3, WHITE, "Q");
    pos = q->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 8);

    /* 3rd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","BP","NN","BQ","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","BP","NN","BP","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete q;
    q = new Queen(0, 6, BLACK, "Q");
    pos = q->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 5);

    /* --------------------------------------------------------------- Rook -----------------------------------------------------------------------------------------------*/
    /* 1st case - beginning of the game */
    Piece *r = new Rook(0, 0, WHITE, "R");
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    pos = r->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 0);

    /* 2nd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","BR","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(3, 3, BLACK, "R");
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 14);

    /* 3rd case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* A */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* B */
            {"WR","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"BR","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"WR","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(3, 0, BLACK, "R");
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 9);

    /* 4th case */
    case_board = {
            /* 1   2    3    4    5     6   7     8 */
            {"NN","NN","NN","NN","NN","NN","WP","WR"}, /* A */
            {"NN","NN","NN","NN","NN","NN","BR","WP"}, /* B */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* C */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* D */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* E */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* F */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}, /* G */
            {"NN","NN","NN","NN","NN","NN","NN","NN"}  /* H */
    };
    board_ptr.reset(new BaseBoard(case_board));
    delete r;
    r = new Rook(0, 7, WHITE, "R");
    pos = r->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 0);

    /* --------------------------------------------------------------- King -----------------------------------------------------------------------------------------------*/
    /* 1st case - beginning of the game */
    Piece *k = new King(4, 0, WHITE, "K");
    board_ptr.reset(new BaseBoard(INITIAL_BOARD));

    pos = k->getPossibleMoves(board_ptr);

    BOOST_CHECK(pos.size() == 0);

    /* 2nd case*/
    case_board = {
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
    k = new King(0, 7, WHITE, "R");
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 3);

    /* 2nd case*/
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
    k = new King(3, 3, WHITE, "R");
    pos = k->getPossibleMoves(board_ptr);
    BOOST_CHECK(pos.size() == 2);
}



