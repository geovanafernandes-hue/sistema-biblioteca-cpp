#!/bin/sh
set -eu
g++ -std=c++11 -Wall -Wextra -pedantic -o biblioteca src/main.cpp
echo "Compilacao concluida. Execute com ./biblioteca"
