#include "lib/King.h"

King::boolean getMoved(){
        return this.moved;
}

King::void setMoved(boolean moved){
        this.moved = moved;
}

King::boolean getCastled(){
        return this.castled;
}

King::void setCastled(boolean castled){
        this.castled = castled;
}

King::boolean getChecked(){
        return this.checked;
}

King::void setChecked(boolean checked){
        this.checked = checked;
}