#!/bin/sh

#Determines whether OpenSSL has been installed and configured
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	if [! -d submodules/openssl]; then
		cd submodules
		git clone https://github.com/openssl/openssl.git
		cd openssl
		./Configure
		make
		sudo make install
		cd ../../
	fi
fi

#Determines whether build folder has been created
if [ ! -d build ]; then
	mkdir build
fi

cd build
cmake .. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl
cmake --build .
# export MallocStackLogging=1
# leaks --atExit -- ./Bitskin-UI
./Bitskin-UI
