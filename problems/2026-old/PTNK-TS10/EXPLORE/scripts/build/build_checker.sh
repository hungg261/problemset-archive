cd ../..

if [ -f "checkers/checker.cpp" ]; then
    echo "Compiling checker..."
    g++ checkers/checker.cpp -I. -O2 -o bin/checker
else
    echo "Checker source not found, skipping."
fi