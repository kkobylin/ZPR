//
// Created by Krzysiek on 29/11/2019.
//
#include "AIClass.h"
#include "../lib/BaseBoard.h"

double AIClass::evaluateBoard(std::shared_ptr<BaseBoard> board, PieceColor side) {

    double result = 0;

    //if(board->isChecking(side == WHITE ? BLACK : WHITE))
      //  result+=40;

//    auto end_of_game = board->checkForWin();
//    switch (side){
//        case WHITE:
//            if(end_of_game == "win")
//                result+= 500;
//            break;
//        case BLACK:
//            if(end_of_game == "lose")
//                result+= 500;
//    }

    for(auto column : board->getBoard())
        for(auto square : column){
            if(square->getOccupied())
                result += square->getPiece()->getPositionValue();
        }

    return result;
}

MovePacket AIClass::MiniMaxRoot(int depth, PieceColor turn, std::shared_ptr<BaseBoard> board_obj, PieceColor side){
    board_type board = board_obj->getBoard();
    MovePacket best_move;
    /* Impossible value for source column to find the first case in searching */
    best_move.src_col = -1;
    for(auto column : board)
        for(auto square : column){
            if(square->getOccupied() && square->getPiece()->getColor() == turn) {
                std::shared_ptr<Piece> piece = square->getPiece();
                auto posMoves = piece->getPossibleMoves(board_obj);
                for(auto pos : posMoves){
                    auto board_obj_string = board_obj->toString();
                    std::shared_ptr<BaseBoard> new_board (new BaseBoard(board_obj_string));
                    new_board->updateBoard(pos.column, pos.row, piece->getColumn(), piece->getRow());
                    if(depth == 1) {
                        int score = evaluateBoard(new_board, side);
                        switch (side) {
                            case BLACK:
                                if (best_move.src_col == -1 || score < best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = score;
                                }
                                break;
                            case WHITE:
                                if (best_move.src_col == -1 || score > best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = score;
                                }
                                break;
                        }
                    } else{//depth > 1
                        PieceColor next_turn = (turn == BLACK ? WHITE : BLACK);
                        MovePacket next_score = MiniMaxRoot(depth - 1, next_turn, new_board, side);
                        switch(side){
                            case BLACK:
                                if(next_score.score < best_move.score){
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = next_score.score;
                                }
                                break;
                            case WHITE:
                                if(next_score.score > best_move.score){
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = next_score.score;
                                }
                                break;
                        }
                    }
                }
            }
        }
    return best_move;
}