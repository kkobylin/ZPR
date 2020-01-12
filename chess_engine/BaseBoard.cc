#include "lib/BaseBoard.h"



extern std::vector <std::vector <std::string>> const INITIAL_BOARD;

//todo zmienic kontruktor zeby dzialal na wskazniku
BaseBoard::BaseBoard(){
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


board_type BaseBoard::getBoard() {
    return board;
}

void BaseBoard::updateBoard(int src_col, int src_row, int dest_col, int dest_row){

}

/*
bool Board::gogoPowerRangers(std::string dest, std::string src){
    std::shared_ptr<BaseBoard> boardInstance = Board::getInstance();
    board_type board = boardInstance->getBoard();

    int src_col = src[0] - 'a'; std::cout << "src_col" << src_col << std::endl; //test
    int src_row = (src[1] - '0') - 1; std::cout << "src_row" << src_row << std::endl; //test
    int dest_col = dest[0] - 'a'; std::cout << "dest_col" << dest_col << std::endl; //test
    int dest_row = (dest[1] - '0') - 1; std::cout << "dest_row" << dest_row << std::endl; //test
    std::cout << "source place of figure: " << board[src_col][src_row]->getPiece() << std::endl; //test

    board[src_col][src_row]->getPiece()->getPossibleMoves();
    std::vector<Position> possiblePositions = board[src_col][src_row]->getPiece()->getMoves();

    for(Position p : possiblePositions){
        if(p.column == dest_col && p.row == dest_row){
            //update board
                //update destination Square
            board[dest_col][dest_row]->setPiece(board[src_col][src_row]->getPiece());
            board[dest_col][dest_row]->setOccupied(true);
            board[dest_col][dest_row]->getPiece()->setPosition(p); // aktualizacja pozycji figury
            //pion poruszony
            if(board[dest_col][dest_row]->getPiece()->getFigureName() == "P"){
                board[dest_col][dest_row]->getPiece()->setMoved();
            }

                //update source Square
            board[src_col][src_row]->setPiece(std::shared_ptr<Piece>{nullptr});
            board[src_col][src_row]->setOccupied(false);


            std::cout << "destination place of figure: " << *(board[dest_col][dest_row]->getPiece()) << std::endl; //test
            return true;

        }
        
    }

    return false;
}
*/
