cd ../..

echo "Compiling generator..."
g++ generators/gen.cpp -I. -O2 -o bin/gen