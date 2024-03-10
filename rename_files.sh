#!/bin/bash

# Change to the directory containing the files you want to rename
cd /path/to/your/directory

# Loop through all files starting with "141_", "142_", and "143_"
for file in 140_* 141_* 142_* 143_* 144_* 145_* 146_*
do
    # Extract the filename without the directory path
    filename=$(basename "$file")
    
    # Replace the first 4 characters with "adv_"
    new_filename="c++_${filename:4}"
    
    # Rename the file
    mv "$file" "$new_filename"
done
