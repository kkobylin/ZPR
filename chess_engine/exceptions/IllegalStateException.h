/**
 * @file IllegalStateException.h
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Exception thrown when program reached state, which should not be reached
 * @version 1.0
 * @date 2020-01-15
 */

#ifndef CHESS_ILLEGALSTATEEXCEPTION_H
#define CHESS_ILLEGALSTATEEXCEPTION_H
#include <exception>

class IllegalStateException : public std::exception {};

#endif //CHESS_ILLEGALSTATEEXCEPTION_H
