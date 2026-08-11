#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..8}
do
    echo "Generating test $i (sub1)"
    ./gen $i 9 a b  > ../tests/$i.inp
done

for i in {9..20}
do
    echo "Generating test $i (sub2)"
    ./gen $i 9 a z  > ../tests/$i.inp
done

for i in {21..40}
do
    echo "Generating test $i (sub3)"
    ./gen $i 1000000 a z  > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
