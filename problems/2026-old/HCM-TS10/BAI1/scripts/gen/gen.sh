#!/bin/bash

cd ../../bin
mkdir -p ../tests

# sub 1
for i in {1..18}
do
    echo "Generating test $i (sub1-valid)"
    ./gen $i --subtask=1 --mode=1 > ../tests/$i.inp
done

for i in {19..20}
do
    echo "Generating test $i (sub1-invalid)"
    ./gen $i --subtask=1 --mode=2 > ../tests/$i.inp
done

# sub 2
for i in {21..28}
do
    echo "Generating test $i (sub2-valid)"
    ./gen $i --subtask=2 --mode=1 > ../tests/$i.inp
done

for i in {29..30}
do
    echo "Generating test $i (sub2-invalid)"
    ./gen $i --subtask=2 --mode=2 > ../tests/$i.inp
done

# sub 3
for i in {31..38}
do
    echo "Generating test $i (sub3-valid)"
    ./gen $i --subtask=3 --mode=1 > ../tests/$i.inp
done

for i in {39..40}
do
    echo "Generating test $i (sub3-invalid)"
    ./gen $i --subtask=3 --mode=2 > ../tests/$i.inp
done

echo
echo "Done."
read -p "Press ENTER to exit..."
