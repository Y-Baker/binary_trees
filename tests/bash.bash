for file in *; do
    if [ -x "$file" ]; then
        mv "$file" tests/
    fi
done
