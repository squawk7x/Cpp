#!/bin/bash

# Path to clang-format executable
CLANG_FORMAT=clang-format

# Directory containing C++ files
DIR=.

# Find all C++ files in the directory
FILES=$(find $DIR -name "*.cpp" -o -name "*.h")

# Loop through each file and format it
for FILE in $FILES; do
    echo "Formatting $FILE"
    $CLANG_FORMAT -i $FILE
done

echo "Formatting complete."
