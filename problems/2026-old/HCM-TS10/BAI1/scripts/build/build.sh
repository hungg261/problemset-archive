#!/bin/bash

./build_solution.sh
./build_brute.sh
./build_checker.sh
./build_gen.sh
./build_validator.sh

echo
echo "Done."
read -p "Press ENTER to exit..."
