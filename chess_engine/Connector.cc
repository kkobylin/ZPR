//
// Created by krzysiek on 01.12.2019.
//

#include "Connector.h"
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "lib/Board.h"
#include <memory>

// todo zmienic board zeby mialo wiersze x kolumny
bool const Connector::ifMovePossible(std::string dest, std::string src){
    return Board::getInstance()->gogoPowerRangers(dest,src);
}


BOOST_PYTHON_MODULE(libchesslib)
        {
                using namespace boost::python;
                def("ifMovePossible", Connector::ifMovePossible)
                ;
        }