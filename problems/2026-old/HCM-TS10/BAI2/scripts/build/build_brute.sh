cd ../..

if [ -f "solutions/brute.cpp" ]; then
    echo "Compiling brute..."
    g++ solutions/brute.cpp -I. -O2 -o bin/brute
else
    echo "Brute-force source not found, skipping."
fi