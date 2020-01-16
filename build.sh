#!/bin/bash


echo "Checking boost version"
BOOST_VER=$(dpkg -s libboost-dev | grep "Version")
if [ -z "${BOOST_VER}" ]
then
	echo "boost not found"
	echo "Installing boost from package"
	sudo apt-get -y install libboost-dev
fi


echo "Checking boost-python version"
BOOST_PYTHON_VER=$(dpkg -s libboost-python-dev | grep "Version")
if [ -z "${BOOST_PYTHON_VER}" ]
then
	echo "boost-python3 not found"
	echo "Installing boost-python"
	sudo apt-get -y install libboost-python3-dev
fi


echo "Checking python version"
PYTHON_VER=$(python3 --version)
if [ -z "${PYTHON_VER}" ]
then
	echo "python not found"
	echo "Installing python from package"
	sudo apt-get -y install libboost-dev
fi


echo "Checking make version"
MAKE_VER=$(make --version)
if [ -z "${MAKE_VER}" ]
then
	echo "python not found"
	echo "Installing python from package"
	sudo apt-get -y install make
fi


echo "Checking cmake version"
CMAKE_VER=$(cmake --version)
if [ -z "${CMAKE_VER}" ]
then
	echo "cmake not found"
	echo "Installing cmake from package"
	sudo apt-get -y install cmake
fi


echo "Checking flask version"
FLASK_VER=$(flask --version)
if [ -z "${FLASK_VER}" ]
then
	echo "flask not found"
	echo "Installing flask from package"
	sudo apt -y install python3-flask
fi


GPP_VER=$(g++-version)
if [ -z "${GPP_VERSION}" ]
then
	echo "gcc not found"
	echo "Installing g++ from package"
	sudo apt-get -y install g++
fi



