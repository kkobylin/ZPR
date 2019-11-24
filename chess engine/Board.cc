#include "lib/Board.h"
#include <iostream>

extern std::vector <std::vector <std::string>> const INITIAL_BOARD;

Board::Board(){
    for (int column = 0; column < 8; column++ ){
        board.push_back(std::vector<Piece *>());
        for (int row = 0; row < 8; row++){
            std::string buffer = INITIAL_BOARD[column][row];
            std::cout << buffer.compare("NN");

         if (buffer.compare("NN")){
                board[column].push_back(new Empty(column, row, BLACK));
                continue; 
            }    

            PieceColor color; 

            if      (buffer[0] == 'B') color = BLACK;
            else if (buffer[0] == 'W') color = WHITE;
            std::cout << column;
            std::cout << row;
            switch(buffer[1]){
            case 'N': board[column].push_back(new Knight(column, row, color)); break;
            case 'R': board[column].push_back(new Rook(column, row, color)); break;
            case 'B': board[column].push_back(new Bishop(column, row, color)); break;
            case 'Q': board[column].push_back(new Queen(column, row, color)); break;
            case 'K': board[column].push_back(new King(column, row, color)); break;
            case 'P': board[column].push_back(new Pawn(column, row, color)); break;
            }
        } 
    }

            
}

std::vector <std::vector <Piece *>> Board::getBoard(){
    return this->board;
}

