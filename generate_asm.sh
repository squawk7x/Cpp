#!/bin/bash

# Check if the input file is provided
if [ -z "$1" ]; then
    echo "Error: No input file specified."
    echo "Usage: $0 input.cpp"
    exit 1
fi

# Check if g++ is installed
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found."
    exit 1
fi

# Compile the input file to generate assembly code
g++ -S -o "${1%.*}.s" "$1"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Error: Compilation failed."
    exit 1
fi

echo "Assembly code generated successfully: ${1%.*}.s"
exit 0
