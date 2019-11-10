#include "Piece.h"

public class King extends Piece{
private:
    private boolean moved = false;
    private boolean castled = false;
    private boolean checked = false;

public:
    boolean setMoved();
    boolean setCastled();
    boolean setChecked();

    void setMoved(boolean moved);
    void setCastled(boolean castled);
    void setChecked(boolean checked);
}