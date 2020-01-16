//
// Created by root on 15.01.2020.
//

#include <boost/test/minimal.hpp>
int test_main(int, char* [] ) { //tak musi sie nazywac główna funkcja
    BOOST_CHECK(1 == 2 );
    BOOST_ERROR("blad");
    BOOST_FAIL("blad krytyczny");
    return 0;
}