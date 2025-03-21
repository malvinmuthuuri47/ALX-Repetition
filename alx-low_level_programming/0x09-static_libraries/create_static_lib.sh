#!/bin/bash

# complle all .c files into .o files
for file in *.c; do
	gcc -c "$file" -o "${file%.c}.o"
done

# create a static library from the object files
ar rcs liball.a *.o

# Clean up the intermediate object files
rm *.o
