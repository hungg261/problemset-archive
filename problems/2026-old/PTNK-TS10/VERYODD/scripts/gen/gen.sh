#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..40}
do
    echo "Generating test $i"
    if [ $i -le 8 ]; then
        ./gen $i 1 > ../tests/$i.inp
    elif [ $i -le 18 ]; then
        ./gen $i 2 > ../tests/$i.inp
    elif [ $i -le 28 ]; then
        ./gen $i 3 > ../tests/$i.inp
    else
        ./gen $i 4 > ../tests/$i.inp
    fi
done

echo
echo "Done."
read -p "Press ENTER to exit..."
