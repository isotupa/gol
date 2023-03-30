#include "gol.h"
#include <unistd.h>
#include <time.h>


int ** init_grid(int f, int c) {
	
	int **grid = (int **) calloc(f, sizeof(int*));


	int i, j;

	for (i = 0; i < f; ++i) {
		grid[i] = (int *) calloc(c, sizeof(int));
	}


	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			grid[i][j] = 0;
		}
	}

	return grid;
}


void print_grid(int ** grid, int f, int c) {
	
	int i, j;
	
	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			if (grid[i][j] == 0) printf("· ");
			else printf("o ");
		}
		printf("\n");
	}
}



void free_grid(int ** grid, int f) {

	int i;

	for (i = 0; i < f; ++i)	free(grid[i]);

	free(grid);
}

void randomize(int ** grid, int f, int c) {
	int i, j;

	srand(time(NULL));

	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			grid[i][j] = rand() % 2;
		}
	}
}


void clr() {
	printf("\x1b[2J");
}


void sleepg(int t) {
	usleep(t);
}

