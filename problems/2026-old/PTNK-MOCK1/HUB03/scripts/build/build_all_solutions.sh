#!/bin/bash

cd ../../solutions

for f in *.cpp
do
    name="${f%.cpp}"
    echo "Compiling $f -> ../bin/$name"
    g++ "$f" -O2 -o "../bin/$name"
done