#include <string>
#include <vector>

enum PieceColor {
    BLACK = 0,
    WHITE = 1
};

const int ROW_MIN = 0;
const int COLUMN_MIN = 0;
const int ROW_MAX = 8;
const int COLUMN_MAX = 8;


public abstract class Piece{
private:
    PieceColor       color;
    int              column;
    int              row;
    boolean          killed();
    std::vector<int> possible_next_move;


public:
    Piece(int, int, PieceColor);

    boolean color();
    void    setKilled(boolean);
    void    setColor(PieceColor);
    void    setRow(int);
    void    setColumn(int);

    PieceColor getColor();
    int                      getColumn();
    int                      getRow();
    boolean                  isKilled();
    virtual std::vector<int> getPossibleNextMove()= 0;
    virtual void             updatePossibleNextMove() = 0;    

}