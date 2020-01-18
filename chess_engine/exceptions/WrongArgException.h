/**
 * @file WrongArgException.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Exception thrown when wrong arguments are passed to function
 * @version 1.0
 * @date 2020-01-15
 */

#ifndef CHESS_WRONGARGEXCEPTION_H
#define CHESS_WRONGARGEXCEPTION_H

#include <exception>
#include <iostream>

class WrongArgException : public std::exception{};

#endif //CHESS_WRONGARGEXCEPTION_H
