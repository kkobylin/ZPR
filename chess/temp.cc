#include "temp.h"
#include <boost/python.hpp>
    Temp::Temp(){
      //  i = 0;
    }

    bool Temp::ifMovePossible(std::string dest, std::string src){
        i++;
           if (i % 2 == 0)
               return true;
           else
               return false;
    }


BOOST_PYTHON_MODULE(chess_logic)
{
    using namespace boost::python;
    def("ifMovePossible", Temp::ifMovePossible);
}