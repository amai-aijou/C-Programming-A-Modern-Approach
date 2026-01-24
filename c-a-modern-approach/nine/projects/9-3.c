/******************************************
 * Name: 8-9.c
 * Purpose: Random walk "worm game"
 * Author: amai-aijou
 * Date: Sat Jan  3 01:07:05 PM CST 2026
 ******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define SIZE ((int) (sizeof(array) / sizeof(array[n][n]))) //array size
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3


void generate_random_walk(char walk[10][10]);

void print_array(char walk[10][10]);

int main(void) {

	int r = 0;
	int c = 0;
	int i, j;
	char array[N][N];
	char ch = 'A';
	int dir;
	bool move[4] = {false, false, false, false};

	// Instantiate array to "." to create the board
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			array[i][j] = '.';
		}
	}

	// Create a random number(need to learn why this has to be called before rand)
	srand((unsigned) time(NULL));

	// Place initial move at 0,0 starting with 'A'
	array[0][0] = ch;

	// Perform rest of random walk movement, with boundary checking
	// 'Z' = 90 in ASCII; game is won upon Z successfully being placed
	while (ch < 90) {

		move[UP] = false;
		move[RIGHT] = false;
		move[DOWN] = false;
		move[LEFT] = false;

		// Check all potential moves and add to move[] array
		if ((r-1 >= 0) && (array[r-1][c] == '.')) {
			move[UP] = true;
		}

		if ((c+1 <= 9) && (array[r][c+1] == '.')) {
			move[RIGHT] = true;
		}
		
		if ((r+1 <= 9) && (array[r+1][c] == '.')) {
			move[DOWN] = true;
		}

		if ((c-1 >= 0) && (array[r][c-1] == '.')) {
			move[LEFT] = true;
		}

		// Check for available moves, terminate early if lost
		if (move[UP] + move[RIGHT] + move[DOWN] + move[LEFT] == 0) {
			printf("*****YOU LOSE.*****\n");
			break;
		}

		// Generate a new direction
		dir = (rand()) % 4;	

		// Attempt to move in that direction
		switch (dir) {
			case UP: //array[r-1][c];
				if (move[UP] == true) {
					r -= 1;
					ch++;
					array[r][c] = (ch);
					break;
				}

			case RIGHT: //array[r][c+1];
				if (move[RIGHT] == true) {
					c += 1;
					ch++;
					array[r][c] = (ch);
					break;
				}
			case DOWN: //array[r+1][c];
				if (move[DOWN] == true) {
					r += 1;
					ch++;
					array[r][c] = (ch);
					break;
				}
			case LEFT: //array[r][c-1];
				if (move[LEFT] == true) {
					c -= 1;
					ch++;
					array[r][c] = (ch);
					break;
				}
		}

		// Check for win condition!
		if (ch == 90) {
			printf("*****YOU WIN!!*****\n");
		}

	}

	// Print board
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void generate_random_walk(char walk[10][10]) {
	//initialize array to contain '.' characters; then, replace with A-Z 
}

void print_array(char walk[10][10]) {
	// Displays the array on screen
}

/*****SCHEMA*****
 * 1. Use srand and rand to generate random numbers
 * 2. Use remainder divided by four (X % 4) to determine cardinal direction of move
 * 3. Check that move won't go outside array; or, overwrite a position already assigned
 * 4. If either condition is violated, move elsewhere. If no moves, terminate
 *
 ***DEBUGGING****
 *	printf("dir: %d\n", dir);
 *	printf("ch: %c\n", ch);
 *	printf("ch: %c\n", ch+1);
 *	printf("potential move up: ok\n");
 *	printf("%d - ch:%c c:%d r:%d\n", dir, ch, c, r);
 */
