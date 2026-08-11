cd ../..

if [ -f "validators/validator.cpp" ]; then
    echo "Compiling validator..."
    g++ validators/validator.cpp -I. -O2 -o bin/validator
else
    echo "Validator source not found, skipping."
fi