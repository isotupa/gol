#include "gol.h"

void show_help(char * program) {
	printf("\nUsage: %s [width] [height] [options]\n", program);
	printf("Width:    integer bigger than 1, preferably smaller than the number of columns displayed by the terminal.\n");
	printf("Height:   integer bigger than 1, preferably smaller than the number of rows displayed by the terminal.\n");
	printf("Options:\n   -h, --help    Display this help message.\n");
	printf("   -t            Set time between iterations. Must be bigger than 0. Values smaller than 0.5 will cause flickering. Default=5.\n");
	printf("   -i            Set maximum number of iteratons or 0 for non-stop. Default=0.\n");
	printf("   -e, --edit    Enter edit mode.\n");
	printf("   -r, --random  Start with random seed and start simulation.\n");
	printf("\nNOTE: if neither -e or -r are set, the simulation will start with all cells dead.\n");
	printf("\nEXIT STATUS:\n  0  if OK\n  1  if problems\n  2  if all cells died.\n\n");
}

