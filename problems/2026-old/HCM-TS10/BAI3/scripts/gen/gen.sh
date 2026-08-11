#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..10}
do
    echo "Generating test $i"
    ./gen $i 1000 TR > ../tests/$i.inp
done

for i in {11..20}
do
    echo "Generating test $i"
    ./gen $i 500000 TR > ../tests/$i.inp
done


for i in {21..25}
do
    echo "Generating test $i"
    ./gen $i 5 TRM > ../tests/$i.inp
done

for i in {26..40}
do
    echo "Generating test $i"
    ./gen $i 500000 TRM > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
