#include "lib/Board.h"
#include <iostream>

extern std::vector <std::vector <std::string>> const INITIAL_BOARD;

Board::Board(){
    for (int row = 0; row < 8; row++){
        board.push_back(std::vector<Piece *>());
        for (int column = 0; column < 8; column++ ){
            std::string buffer = INITIAL_BOARD[column][row];
            //std::cout << buffer;
            std::cout << column;
            std::cout << row;

         if (buffer.compare("NN") == 0){
                board[row].push_back(new Empty(column, row, false));
                //std::cout << "NN" << std::endl;
                continue; 
            }    

            PieceColor color; 

            if      (buffer[0] == 'B') color = BLACK;
            else if (buffer[0] == 'W') color = WHITE;

            switch(buffer[1]){
            case 'N': board[column].push_back(new Knight(column, row, color));std::cout << "N" << std::endl; break;
            case 'R': board[column].push_back(new Rook(column, row, color));std::cout << "R" << std::endl; break;
            case 'B': board[column].push_back(new Bishop(column, row, color));std::cout << "B" << std::endl; break;
            case 'Q': board[column].push_back(new Queen(column, row, color));std::cout << "Q" << std::endl; break;
            case 'K': board[column].push_back(new King(column, row, color));std::cout << "K" << std::endl; break;
            case 'P': board[column].push_back(new Pawn(column, row, color));std::cout << "P" << std::endl; break;
            }
        } 
    }
    

            
}

std::vector <std::vector <Piece *>> Board::getBoard(){
    return this->board;
}

