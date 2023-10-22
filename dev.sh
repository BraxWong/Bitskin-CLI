#!/bin/sh

cd build
cmake ..
cmake --build .
# export MallocStackLogging=1
# leaks --atExit -- ./Bitskin-UI
./Bitskin-UI
