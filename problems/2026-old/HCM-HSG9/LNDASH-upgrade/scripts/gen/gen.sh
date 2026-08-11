#!/bin/bash

cd ../../bin
mkdir -p ../tests

for i in {1..100}
do
    PARAM="max"
    
    if [ $i -le 20 ]; then
        SUB="sub1"
        [ $i -le 5 ] && PARAM="small"
    elif [ $i -le 40 ]; then
        SUB="sub2"
        [ $i -le 25 ] && PARAM="small"
    elif [ $i -le 60 ]; then
        SUB="sub3"
        [ $i -le 45 ] && PARAM="small"
    elif [ $i -le 90 ]; then
        SUB="sub4"
        [ $i -le 65 ] && PARAM="small"
    else
        SUB="sub5"
        [ $i -eq 91 ] && PARAM="small"
    fi

    echo "Generating test $i ($SUB - $PARAM)"
    ./gen $i $SUB $PARAM > "../tests/$i.inp"
done

echo
echo "Done."
read -p "Press ENTER to exit..."
