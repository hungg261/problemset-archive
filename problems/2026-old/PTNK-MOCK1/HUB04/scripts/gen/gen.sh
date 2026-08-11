#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..5}
do
    echo "Generating test $i"
    ./gen $i sub1 > ../tests/$i.inp
done

for i in {6..7}
do
    echo "Generating test $i"
    ./gen $i sub2-small > ../tests/$i.inp
done

for i in {8..10}
do
    echo "Generating test $i"
    ./gen $i sub2 > ../tests/$i.inp
done

for i in {11..20}
do
    echo "Generating test $i"
    ./gen $i sub3 > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
