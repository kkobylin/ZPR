//
// Created by Krzysiek on 29/11/2019.
//

#ifndef CHESS_TEMP_H
#define CHESS_TEMP_H
#include <string>
#include <boost/python/module.hpp>
class Temp{
    inline static int i = 0;

public:
    Temp();
    bool ifMovePossible(std::string dest, std::string src);
};

#endif //CHESS_TEMP_H
