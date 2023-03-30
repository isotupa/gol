gol:
	gcc -Wall -Wextra -c src/*
	gcc -o bin/gol *.o
	rm *.o
