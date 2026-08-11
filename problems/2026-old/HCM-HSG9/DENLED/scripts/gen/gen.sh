#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..29}
do
    echo "Generating test $i"
    ./gen $i sub1 random > ../tests/$i.inp
done

for i in {30..30}
do
    echo "Generating test $i"
    ./gen $i sub1 max > ../tests/$i.inp
done


for i in {31..49}
do
    echo "Generating test $i"
    ./gen $i sub2 random > ../tests/$i.inp
done

for i in {50..50}
do
    echo "Generating test $i"
    ./gen $i sub2 max > ../tests/$i.inp
done


for i in {51..69}
do
    echo "Generating test $i"
    ./gen $i sub3 random > ../tests/$i.inp
done

for i in {70..70}
do
    echo "Generating test $i"
    ./gen $i sub3 max > ../tests/$i.inp
done


for i in {71..99}
do
    echo "Generating test $i"
    ./gen $i sub4 random > ../tests/$i.inp
done

for i in {100..100}
do
    echo "Generating test $i"
    ./gen $i sub4 max > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
