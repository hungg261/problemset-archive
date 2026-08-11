#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..10}
do
    echo "Generating test $i"
    ./gen $i sub1-small > ../tests/$i.inp
done

for i in {11..40}
do
    echo "Generating test $i"
    ./gen $i sub1 > ../tests/$i.inp
done

for i in {41..100}
do
    echo "Generating test $i"
    ./gen $i sub2 > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
