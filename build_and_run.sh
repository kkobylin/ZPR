#!/bin/sh
echo "change directory to chess_engine"
cd chess_engine
cmake CMakeLists.txt
make
echo "run tests"
cd test
cmake CMakeLists.txt
make 
echo "run tests"
./tests
cd ..
echo "change directory do ZPR_do_wyslania"
cd ..
cd web
echo "run server.py"
python3 server.py


