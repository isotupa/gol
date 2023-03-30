#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALIVE 1
#define DEAD 0


/*  canvas.c headers   */

// Initialize grid using dynamic memory allocation
int ** init_grid( int f, int c );

// Print given grid
void print_grid(int ** grid, int f, int c);

// Free memory used by the given grid
void free_grid(int ** grid, int f);

// Set to random values grid
void randomize(int ** grid, int f, int c);

// Clear screen. Depending on the terminal used, this might give way to
// errors. Tested on Gnome's and Mint's terminal.
void clr( void );

// Sleep for the given amount of time.
void sleepg(int t);


/*   rules.c headers   */

// Private function used to count the neighbours surrounding the
// given x, y positon. It wraps around the grid if -w is not set.
int count_neighbours(int ** grid, int rows, int cols, int x, int y);

// Updates the grid with the rules.
int update_grid(int ** grid, int ** next, int f, int c);


/*   edit.c headers   */

// Enters edit mode
void edit(int ** grid, int f, int c);

// Private function
void wrong();


/*   help.c headers   */

// Shows main help message.
void show_help(char * program);

// Checks the flags.
void check_flags();

