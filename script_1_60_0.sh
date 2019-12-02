#!/bin/sh
echo "installing required packages"
echo "add universe repository"
sudo add-apt-repository universe
echo "apt-get update"
sudo apt-get -y update
echo "install libboost dev"
sudo apt-get -y install libboost-all-dev
echo "getting boost_1_60_0"
FILE=~/Downloads/boost_1_60_0.tar.bz2
if test -f "$FILE"; then
    echo "$FILE exist"
else
	wget -O ~/Downloads/boost_1_60_0.tar.bz2 https://sourceforge.net/projects/boost/files/boost/1.60.0/boost_1_60_0.tar.bz2/download

fi 
echo "creating folder on desktop"
mkdir ~/Desktop/Boost
echo "change directory do ~/Desktop/Boost"
cd ~/Desktop/Boost/
pwd
echo "unpacking boost_1_60_0"
tar --bzip2 -xf ~/Downloads/boost_1_60_0.tar.bz2
echo "change directory to ~/Desktop/Boost/boost_1_60_0"
cd ~/Desktop/Boost/boost_1_60_0/
echo "Bootstrap files"
./bootstrap.sh gcc --with-python=PYTHON
echo "clean"
./b2 clean
echo "building"
./b2 --with-python link=static cxxflags="-std=c++11 -fPIC" variant=release stage
./b2 --with-python link=static cxxflags="-std=c++11 -fPIC" variant=release install
echo "installing flask"
sudo apt install -y python3-flask
echo "finished"


