#include "gol.h"

int main(int argc, char ** argv) {

	if (argc < 3) {
		show_help(argv[0]);
		return 1;
	}

	int f = atoi(argv[1]);
	int c = atoi(argv[2]);

	if (f < 2 || c < 2) {
		printf("Invalid argument/s: width & height must be bigger than 1!\n");
		return 1;
	}

	int iterations = 0;
	float speed = 500000;


	int **grid = init_grid(f, c);
	int **next = init_grid(f,c);

	int a, ed = 0, rand = 0, i;

	for (a = 3; a <argc; ++a) {
		if (strcmp("-h", argv[a]) == 0 || strcmp("--help", argv[a]) == 0) {
			show_help(argv[0]);
			return 1;
		}
		else if (strcmp("-t", argv[a]) == 0) {
			speed = atof(argv[a+1]) * 100000;
			if (speed <= 0) {
				printf("Invalid argument/s: time must be bigger than 0!\n");
				return 1;
			}
			++a;
		}
		else if (strcmp("-i", argv[a]) == 0) {
			iterations = atoi(argv[a+1]);
			++a;
		}
		else if (strcmp("-e", argv[a]) == 0 || strcmp("--edit", argv[a]) == 0) {
			ed = 1;
		}
		else if (strcmp("-r", argv[a]) == 0 || strcmp("--random", argv[a]) == 0) {
			rand = 1;
		}
		else {
			printf("Invalid option/s!\n");
			printf("Use --help or -h to display help message\n");
			return 1;
		}
	}


	if (rand == 1) randomize(grid, f, c);
	if (ed == 1) edit(grid, f, c);

	grid[5][5] = ALIVE;
	grid[6][5] = ALIVE;
	grid[7][5] = ALIVE;
	grid[7][4] = ALIVE;
	grid[6][3] = ALIVE;

	for (i = 1; iterations == 0 ? 1 : i <= iterations; ++i) {
		clr();
		print_grid(grid, f, c);
		printf("Iteration number: %i\n", i);
		if (update_grid(grid, next, f, c) == 2) return 0;
		sleepg(speed);
	}



	free_grid(grid, f);

	return 0;
}
