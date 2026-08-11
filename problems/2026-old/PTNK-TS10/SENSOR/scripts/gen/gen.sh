#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..5}
do
    echo "Generating test $i (sub1-small)"
    ./gen $i 5 9 1 > ../tests/$i.inp
done

for i in {6..10}
do
    echo "Generating test $i (sub1)"
    ./gen $i 300 1000000000 1 > ../tests/$i.inp
done

for i in {11..20}
do
    echo "Generating test $i (sub2)"
    ./gen $i 3000 1000000000 1 > ../tests/$i.inp
done

for i in {21..25}
do
    echo "Generating test $i (sub3-weak)"
    ./gen $i 300000 100 0 > ../tests/$i.inp
done

for i in {26..40}
do
    echo "Generating test $i (sub3)"
    ./gen $i 300000 1000000000 1 > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
