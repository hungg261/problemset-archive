cd ../../bin
touch .inp .out .ans

i=1
while true
do
    ./gen $i small > .inp
    ./solution < .inp > .out
    ./brute < .inp > .ans

    ./checker.exe .inp .ans .out > /dev/null || break

    echo "Passed test $i"
    ((i++))
done

echo
echo "Wrong answer found at test $i"
read -p "Press ENTER to exit..."