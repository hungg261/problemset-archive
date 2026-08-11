#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..20}
do
    echo "Generating test $i"
    ./gen $i > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
