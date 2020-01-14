//
// Created by Krzysiek on 29/11/2019.
//
#include "AIClass.h"
#include "../lib/BaseBoard.h"

double AIClass::evaluateBoard(board_type board) {

    double result = 0;

    for(auto column : board)
        for(auto square : column){
            if(square->getOccupied())
                result += square->getPiece()->getPositionValue();
        }

    return result;
}

MovePacket AIClass::MiniMaxRoot(int depth, PieceColor turn, std::shared_ptr<BaseBoard> boardObj, PieceColor side){
    board_type board = boardObj->getBoard();
    MovePacket bestMove;
    /* Impossible value for source column to find the first case in searching */
    bestMove.src_col = -1;
    for(auto column : board)
        for(auto square : column){
            if(square->getOccupied() && square->getPiece()->getColor() == turn) {
                std::shared_ptr<Piece> piece = square->getPiece();
                auto posMoves = piece->getPossibleMoves(boardObj);
                for(auto pos : posMoves){
                    auto boardObjString = boardObj->toString();
                    std::shared_ptr<BaseBoard> newBoard (new BaseBoard(boardObjString));
                    newBoard->updateBoard(pos.column, pos.row, piece->getColumn(), piece->getRow());
                    if(depth == 1) {
                        int score = evaluateBoard(newBoard->getBoard());
                        switch (side) {
                            case BLACK:
                                if (bestMove.src_col == -1 || score < bestMove.score) {
                                    bestMove.src_row = piece->getRow();
                                    bestMove.src_col = piece->getColumn();
                                    bestMove.dest_row = pos.row;
                                    bestMove.dest_col = pos.column;
                                    bestMove.score = score;
                                }
                                break;
                            case WHITE:
                                if (bestMove.src_col == -1 || score > bestMove.score) {
                                    bestMove.src_row = piece->getRow();
                                    bestMove.src_col = piece->getColumn();
                                    bestMove.dest_row = pos.row;
                                    bestMove.dest_col = pos.column;
                                    bestMove.score = score;
                                }
                                break;
                        }
                    } else{//depth > 1
                        PieceColor nextTurn = (turn == BLACK ? WHITE : BLACK);
                        MovePacket nextScore = MiniMaxRoot(depth - 1, nextTurn, newBoard, side);
                        switch(side){
                            case BLACK:
                                if(nextScore.score < bestMove.score){
                                    bestMove.src_row = piece->getRow();
                                    bestMove.src_col = piece->getColumn();
                                    bestMove.dest_row = pos.row;
                                    bestMove.dest_col = pos.column;
                                    bestMove.score = nextScore.score;
                                }
                                break;
                            case WHITE:
                                if(nextScore.score > bestMove.score){
                                    bestMove.src_row = piece->getRow();
                                    bestMove.src_col = piece->getColumn();
                                    bestMove.dest_row = pos.row;
                                    bestMove.dest_col = pos.column;
                                    bestMove.score = nextScore.score;
                                }
                                break;
                        }
                    }
                }
            }
        }
    return bestMove;
}