//
// Created by root on 14.01.2020.
//

#ifndef CHESS_WRONGARGEXCEPTION_H
#define CHESS_WRONGARGEXCEPTION_H

#include <exception>
#include <iostream>

class WrongArgException : public std::exception
{
    std::string text;
public:
    WrongArgException(std::string text);
};

#endif //CHESS_WRONGARGEXCEPTION_H
