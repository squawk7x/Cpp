# Source directory CMakeLists.txt

# Add all source files in the directory to a variable
set(SOURCES
    main.cpp
    # Add more source files here as needed
)

# Create an executable target using the source files
add_executable(a.out ${SOURCES})
