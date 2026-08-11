cd ../../tests

shopt -s nullglob

for f in ./*.inp; do
    echo "=== Checking: $f ==="
    ../bin/validator < "$f"
    echo "Exit code: $?"
    echo
done

echo
echo "Done."
read -p "Press ENTER to exit..."
