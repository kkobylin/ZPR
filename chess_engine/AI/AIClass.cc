/**
 * @file AIClass.cc
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Class calculating opponent move, using minmax algorithm
 * @version 1.0
 * @date 2020-01-15
 */
#include "AIClass.h"
#include "../lib/BaseBoard.h"

double AIClass::evaluateBoard(std::shared_ptr<BaseBoard> board, PieceColor side) {

    double result = 0;

    for(auto column : board->getBoard())
        for(auto square : column){
            if(square->getOccupied())
                /* Multiply by 3 to encourage AI to attack instead of just rearrange pieces */
                result += square->getPiece()->getPositionValue() * 3;
        }

    return result;
}

MovePacket AIClass::MiniMaxRoot(int depth, PieceColor turn, std::shared_ptr<BaseBoard> board_obj, double alpha, double beta) {
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
                        double score = evaluateBoard(new_board, turn);
                        switch (turn) {
                            case BLACK: {
                                beta = std::min(beta, score);
                                if (best_move.src_col == -1 || score < best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = score;
                                }
                                break;
                            }
                            case WHITE: {
                                alpha = std::max(alpha, score);
                                if (best_move.src_col == -1 || score > best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = score;
                                }
                                break;
                            }
                        }
                        if(beta <= alpha)
                            return best_move;
                    } else{//depth > 1
                        PieceColor next_turn = (turn == BLACK ? WHITE : BLACK);
                        MovePacket next_score = MiniMaxRoot(depth - 1, next_turn, new_board, alpha, beta);
                        switch(turn){
                            case BLACK: {
                                if (best_move.src_col == -1 || next_score.score < best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = next_score.score;
                                }
                                beta = std::min(beta, next_score.score);
                                break;
                            }
                            case WHITE: {
                                if (best_move.src_col == -1 || next_score.score > best_move.score) {
                                    best_move.src_row = piece->getRow();
                                    best_move.src_col = piece->getColumn();
                                    best_move.dest_row = pos.row;
                                    best_move.dest_col = pos.column;
                                    best_move.score = next_score.score;
                                }
                                alpha = std::max(alpha, next_score.score);
                                break;
                            }
                        }
                       if(beta <= alpha)
                           return best_move;
                    }
                }
            }
        }
    if(best_move.src_col == -1){
        switch(turn){
            case BLACK:
                best_move.score = std::numeric_limits<double>::max();
                break;
            case WHITE:
                best_move.score = std::numeric_limits<double>::max() * -1;
                break;
        }
    }

    return best_move;
}

