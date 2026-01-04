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

	/* Debugging
	printf("dir: %d\n", dir);
	printf("ch: %c\n", ch);
	printf("ch: %c\n", ch+1);
	*/

	// Place initial move at 0,0 starting with 'A'
	array[0][0] = ch;

	// Perform rest of random walk movement, with boundary checking
	// 'Z' = 90 in ASCII
	while (ch < 90) {

		move[UP] = false;
		move[RIGHT] = false;
		move[DOWN] = false;
		move[LEFT] = false;

		// Check all potential moves and add to move[] array
		if ((r-1 >= 0) && (array[r-1][c] == '.')) {
			move[UP] = true;
			printf("potential move up: ok\n");
		}

		if ((c+1 <= 9) && (array[r][c+1] == '.')) {
			move[RIGHT] = true;
			printf("potential move right: ok\n");
		}
		
		if ((r+1 <= 9) && (array[r+1][c] == '.')) {
			move[DOWN] = true;
			printf("potential move down: ok\n");
		}

		if ((c-1 >= 0) && (array[r][c-1] == '.')) {
			move[LEFT] = true;
			printf("potential move left: ok\n");
		}

		if (move[UP] + move[RIGHT] + move[DOWN] + move[LEFT] == 0) {
			printf("*****YOU LOSE.*****\n");
			break;
		}

		// Generate a new direction
		dir = (rand()) % 4;	

		// Attempt to move in that direction
		switch (dir) {
			case UP: //array[c-1][r];
				if (move[UP] == true) {
					r -= 1;
					ch++;
					array[r][c] = (ch);
					printf("0 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}

			case RIGHT: //array[c][r+1];
				if (move[RIGHT] == true) {
					c += 1;
					ch++;
					array[r][c] = (ch);
					printf("1 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
			case DOWN: //array[c+1][r];
				if (move[DOWN] == true) {
					r += 1;
					ch++;
					array[r][c] = (ch);
					printf("2 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
			case LEFT: //array[c][r-1];
				if (move[LEFT] == true) {
					c -= 1;
					ch++;
					array[r][c] = (ch);
					printf("3 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
		}
/*
//		if ((array[r-1][c] != '.') && (array[r][c+1] != '.') && (array[r+1][c] != '.') && (array[r][c-1] != '.')) {

			//printf("NO - ch:%c c:%d r:%d\n", ch, c, r);
//			printf("*****YOU LOSE.*****\n");
//			break;
		//}
//		|| ((move[0] == false) && (move[1] == false) && (move[2] == false)  && (move[3] == false))
*/
		if (ch == 90) {
			printf("*****YOU WIN!!*****\n");
		}

	}

	printf("ch:%c\n", ch);
	// Print board
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*****SCHEMA*****
 * 1. Use srand and rand to generate random numbers
 * 2. Use remainder divided by four (X % 4) to determine cardinal direction of move
 * 3. Check that move won't go outside array; or, overwrite a position already assigned
 * 4. If either condition is violated, move elsewhere. If no moves, terminate
 */
