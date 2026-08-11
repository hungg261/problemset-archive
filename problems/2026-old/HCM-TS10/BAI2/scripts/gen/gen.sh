#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..3}
do
    echo "Generating test $i"
    ./gen -subtask 1 -n 2 -m 5 $i > ../tests/$i.inp
done

for i in {4..10}
do
    echo "Generating test $i"
    ./gen -subtask 1 -n 2 -m 100000 $i > ../tests/$i.inp
done

for i in {11..20}
do
    echo "Generating test $i"
    ./gen -subtask 2 -n 100000 -m 100000 -r 1 $i > ../tests/$i.inp
done

for i in {21..40}
do
    echo "Generating test $i"
    ./gen -subtask 3 -n 100000 -m 100000 $i > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
