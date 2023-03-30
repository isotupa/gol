#include "gol.h"


int count_neighbours(int ** grid, int rows, int cols, int x, int y) {
	int sum = 0, i, j, col, row;

	for (i = -1; i < 2; ++i) {
		for (j = -1; j < 2; ++j) {
			col = (x + i + rows) % rows;
			row = (y + j + cols) % cols;

			sum += grid[col][row];
		}
	}
	return sum - grid[x][y];
}

int update_grid(int ** grid, int ** next, int f, int c) {
	int i, j, nlive, has_changed;
	has_changed = 0;

	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			
			nlive = count_neighbours(grid, f, c, i, j);
			int state = grid[i][j];
			
			if (state != 0) has_changed = 1;

			if (state == ALIVE) has_changed = 1;
			// Underpopulation
			if (state == ALIVE && nlive < 2) next[i][j] = DEAD;
			// Survival
			else if ((state == ALIVE && nlive == 2) || (state == ALIVE && nlive == 3)) next[i][j] = ALIVE;
			// Overpopulation
			else if (state == ALIVE && nlive > 3) next[i][j] = DEAD;
			// Reproduction
			else if (state == DEAD && nlive == 3) next[i][j] = ALIVE;
			else next[i][j] = state;
		}
	}

	if (has_changed == 0) return 2;

	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			int x = next[i][j];
			grid[i][j] = x;
		}
	}


	return 1;
}
