//
// Created by Krzysiek on 29/11/2019.
//

#include "temp.h"
#include <iostream>

using namespace std;

int main(void){
    Temp* temp1 = new Temp();
    for(int i =0; i< 5; i++) {
        bool ans = temp1->ifMovePossible("G1", "A2");
        cout << ans << endl;
    }
    return 0;
}

