#include "lib/BaseBoard.h"
#include <memory>
#include "lib/Piece.h"
#include "lib/Bishop.h"
#include "lib/Rook.h"
#include "lib/Knight.h"
#include "lib/King.h"
#include "lib/Queen.h"
#include "lib/Pawn.h"


#include "lib/Piece.h"
#include "lib/Bishop.h"
#include "lib/Rook.h"
#include "lib/Knight.h"
#include "lib/King.h"
#include "lib/Queen.h"
#include "lib/Pawn.h"

extern std::vector <std::vector <std::string>> const INITIAL_BOARD;

BaseBoard::BaseBoard(std::vector <std::vector <std::string>> board_string){
    for (int column = 0; column < 8; column++){
        board.push_back(std::vector<std::shared_ptr<Square>>());
        for (int row = 0; row < 8; row++ ){
            
            std::string buffer = board_string[column][row];

             if (buffer.compare("NN") == 0){
                    board[column].push_back(std::shared_ptr<Square>{new Square(nullptr)});
                    board[column].back()->setColumn(column);
                    board[column].back()->setRow(row);
                    continue;
            }

            PieceColor color; 

            if      (buffer[0] == 'B') color = BLACK;
            else if (buffer[0] == 'W') color = WHITE;

            std::string name (1, buffer[1]);
            switch(buffer[1]){
            //TODO pozmieniac na Square
            case 'N':
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<Knight>{new Knight(column, row, color, name)})});
                break;
            case 'R': 
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<Rook>{new Rook(column, row, color, name)})});
                break;
            case 'B': 
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<Bishop>{new Bishop(column, row, color, name)})});
                break;
            case 'Q': 
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<Queen> {new Queen(column, row, color, name)})});
                break;
            case 'K': 
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<King>{new King(column, row, color, name)})});
                break;
            case 'P': 
                board[column].push_back(std::shared_ptr<Square>{
                new Square(
                std::shared_ptr<Pawn>{new Pawn(column, row, color, name)})});
                break;
            }
            board[column][row]->setOccupied(true);
            board[column][row]->setColumn(column);
            board[column][row]->setRow(row);

            if (buffer != INITIAL_BOARD[column][row]){
                board[column][row]->getPiece()->setMoved();
            }
        } 
    }
}

board_type BaseBoard::getBoard() {
    return board;
}

void BaseBoard::updateBoard(int dest_col, int dest_row, int src_col, int src_row){
            //update board
                //update destination Square
            Position position {dest_col, dest_row};
            board[dest_col][dest_row]->setPiece(board[src_col][src_row]->getPiece());
            board[dest_col][dest_row]->setOccupied(true);
            board[dest_col][dest_row]->getPiece()->setPosition(position); // aktualizacja pozycji figury
            board[dest_col][dest_row]->getPiece()->setMoved();

                //update source Square
            board[src_col][src_row]->setPiece(std::shared_ptr<Piece>{nullptr});
            board[src_col][src_row]->setOccupied(false);
}


std::vector <std::vector <std::string>> BaseBoard::toString(){
    std::vector <std::vector <std::string>> board_return;
    std::string piece = "";
    std::string color = "";

    for (int column = 0; column < 8; column++){
        board_return.push_back(std::vector<std::string>());
        for (int row = 0; row < 8; row++){
            if (board[column][row]->getOccupied()){
                if(board[column][row]->getPiece()->getColor() == WHITE){
                    color = "W";
                }else{
                    color = "B";
                }
                    
                piece = board[column][row]->getPiece()->getFigureName();
                board_return[column].push_back(color + piece);
            }else
            {
                board_return[column].push_back("NN");
            }
            
        }
    }

    return board_return;

}

void BaseBoard::printBoardCout(){
    std::cout << "Current Board:" << std::endl;
    for (int column = 0; column < 8; column++){
        for (int row = 0; row < 8; row++){
            std::cout <<(char)(board[column][row]->getColumn() + 65)  << board[column][row]->getRow() + 1  <<this->toString()[column][row] << " " ;
            if (row == 7){
                std::cout << std::endl;
            }
        }
    }
}

