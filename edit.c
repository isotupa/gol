#include "gol.h"

void edit(int ** grid, int f, int c) {
	int i, j, k;
	char ch;
	char * pch = &ch;

	for (i = 0; i < f; ++i) {
		for (j = 0; j < c; ++j) {
			do {
				clr();
				if (c < 11) printf("\n=Edit mode=\n");
				else {
				printf("\n");
					for (k = 0; k < (c-5)/2; ++k, printf("= "));
					printf("Edit mode ");
					for (k = 0; k < (c-5)/2; ++k, printf("= "));
					printf("\n");
				}


				int a, b;
				for (a = 0; a < f; ++a) {
					for (b = 0; b < c; ++b) {
						if (i == a && j == b) printf("X ");
						else if (grid[a][b] == 0) printf("· ");
						else printf("o ");
					}
					printf("\n");
				}



				
				printf("\nf to flip current position's value\n");
				printf("p to go to the previous position\n");
				printf("n to go to the next position\n");
				printf("r to go to the next row\n");
				printf("b to go back a row\n");
				printf("q to stop editing and run the simulation.\n\n");
				printf("Enter command for position (%i, %i): ", i, j);

				scanf(" %c", pch);

				if (ch == 'f') grid[i][j] = (grid[i][j]==ALIVE?DEAD:ALIVE);
				else if (ch == 'p') {
					if (j == 0) wrong(), --j;
					else j -= 2;
				}
				else if (ch == 'r') {
					if (i == f-1) wrong(), --j;
					else ++i, --j;
				}
				else if (ch == 'q') return;
				else if (ch == 'n') {
					if (j == c-1) wrong(), --j;
					else j+= 0.5;
				}
				else if (ch == 'b') {
					if (i == 0) wrong(), --j;
					else --i, --j;
				}
				else {
					clr();
					printf("Wrong command!\n");
					sleepg(900000);
				}
				
			}
			while ((ch != 'f' && ch != 'p') && (ch != 'r' && ch != 'q') && (ch != 'n' && ch != 'b'));

		}
	}
}


void wrong() {
	clr();
	printf("Invalid value!\n");
	sleepg(900000);
}
