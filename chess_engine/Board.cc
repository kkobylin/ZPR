#include "lib/Board.h"
#include <iostream>
#include <memory>

std::shared_ptr<Board> Board::instance = nullptr;
extern std::vector <std::vector <std::string>> const INITIAL_BOARD;

//todo zmienic kontruktor zeby dzialal na wskazniku
Board::Board(){
    for (int column = 0; column < 8; column++){
        board.push_back(std::vector<std::shared_ptr<Square>>());
        for (int row = 0; row < 8; row++ ){
            
            std::string buffer = INITIAL_BOARD[row][column];

         if (buffer.compare("NN") == 0){
                //std::string name (1, 'E'); teraz niepotrzebne
                board[column].push_back(std::shared_ptr<Square>{
                new Square
                (nullptr)});
                board[column].back()->setColumn(column);
                board[column].back()->setRow(row);
                continue; 
        }    

            PieceColor color; 

            if      (buffer[0] == 'B') color = BLACK;
            else if (buffer[0] == 'W') color = WHITE;

            std::string name (1, buffer[1]);
        std::cout << "dotarlismy";
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
            board[column].back()->setOccupied(true);
            board[column].back()->setColumn(column);
            board[column].back()->setRow(row);
        } 
    }
            
}

std::shared_ptr<Board> Board::getInstance(){
    if(!instance)
        instance = std::shared_ptr<Board> (new Board());
    return instance;
}

board_type Board::getBoard() {
    return board;
}

void Board::updateBoard(int src_col, int src_row, int dest_col, int dest_row){

}

