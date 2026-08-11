#!/bin/bash

# detect problem folder name
name=$(basename "$PWD")

echo "Problem code: $name"

# rename statement markdown
if [ -f "statement/.md" ]; then
    mv statement/.md "statement/$name.md"
    echo "Renamed statement/.md -> statement/$name.md"
fi

# input fields
read -e -p "Title: " title
read -e -p "Source: " source
read -e -p "Difficulty (easy/medium/hard/olympiad): " difficulty
read -e -p "Rating: " rating
read -e -p "Tags (comma separated): " tags_input
read -e -p "Time limit (sec): " time_limit
read -e -p "Memory limit (MB): " memory_limit
read -e -p "Interactive (Y/N): " interactive_input

# remove control characters
tags_input=$(printf '%s' "$tags_input" | sed 's/[^[:print:], ]//g')

# split tags
IFS=',' read -ra TAGS <<< "$tags_input"

# interactive boolean
interactive=false
if [[ "$interactive_input" =~ ^[Yy]$ ]]; then
    interactive=true
fi

# start writing JSON
{
echo "{"
echo "  \"name\": \"$name\","
echo "  \"title\": \"$title\","
echo ""
echo "  \"source\": \"$source\","
echo "  \"difficulty\": \"$difficulty\","
echo "  \"rating\": $rating,"
echo ""
echo "  \"tags\": ["

count=${#TAGS[@]}
for i in "${!TAGS[@]}"; do
    tag=$(echo "${TAGS[$i]}" | xargs)

    if [ "$i" -lt $((count-1)) ]; then
        printf '    "%s",\n' "$tag"
    else
        printf '    "%s"\n' "$tag"
    fi
done

echo "  ],"
echo ""
echo "  \"limits\": {"
echo "    \"time_limit_sec\": $time_limit,"
echo "    \"memory_limit_mb\": $memory_limit"
echo "  },"
echo ""
echo "  \"interactive\": $interactive"
echo "}"

} > problem.json

echo
echo "problem.json created!"

read -p "Press ENTER to exit..."