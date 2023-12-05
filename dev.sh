#!/bin/sh

cd build
cmake .. -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl
cmake --build .
# export MallocStackLogging=1
# leaks --atExit -- ./Bitskin-UI
./Bitskin-UI
