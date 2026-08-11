#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..2} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 10 15 1 0 1 -2 > ../tests/$i.inp
done

for i in {3..4} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 500 500 1 0 1 -2 > ../tests/$i.inp
done

for i in {5..6} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 10 15 1 0 5 -2 > ../tests/$i.inp
done

for i in {7..9} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 50 80 1 0 5 -2 > ../tests/$i.inp
done

for i in {10..14} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 500 500 1 0 5 -2 > ../tests/$i.inp
done

for i in {15..19} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 200 200 5 0 -1 0 > ../tests/$i.inp
done

for i in {20..24} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 500 500 8 0 -1 1 > ../tests/$i.inp
done

for i in {25..30} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 150 150 4 1 -1 0 > ../tests/$i.inp
done

for i in {31..36} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 500 500 6 1 -1 1 > ../tests/$i.inp
done

for i in {37..43} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 300 300 12 -1 -1 0 > ../tests/$i.inp
done

for i in {44..50} # 2.0pts/test
do
    echo "Generating test $i"
    ./gen $i 500 500 26 -1 -1 1 > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
