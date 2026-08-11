cd ../../bin
touch .inp .out .ans

i=1
while true
do
    ./gen $i > .inp
    ./solution < .inp > .out
    ./brute < .inp > .ans
    diff -w .out .ans || break
    echo "Passed test $i"
    ((i++))
done

echo
echo "Wrong answer!"
read -p "Press ENTER to exit..."