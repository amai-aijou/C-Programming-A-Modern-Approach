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

int main(void) {

	int r = 0;
	int c = 0;
	int i, j;
	char array[N][N];
	char ch = 'A';
	int dir;

	// Instantiate array to "." to create the board
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			array[i][j] = '.';
		}
	}

	// Create a random number(need to learn why this has to be called before rand)
	srand((unsigned) time(NULL));


	

	/* Debugging
	dir = (rand()) % 4;	

	printf("dir: %d\n", dir);
	printf("ch: %c\n", ch);
	printf("ch: %c\n", ch+1);

	NOTE: Additional debugging printf statements sprinkled throughout in comments
	*/

	// Place initial move at 0,0 starting with 'A'
	array[0][0] = ch;
	//printf("ch: %c\n", ch);

	// Perform rest of random walk movement, with boundary checking
	// 'Z' = 90 in ASCII
	while (ch < 90) {

	dir = (rand()) % 4;	

		switch (dir) {
			case 1: //array[c-1][r];
				if ((c-1 >= 0) && (array[c-1][r] == '.')) {
					c -= 1;
					ch++;
					array[c][r] = (ch);
					printf("1 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}

			case 2: //array[c][r+1];
				if ((r+1 <= 9) && (array[c][r+1] == '.')) {
					r += 1;
					ch++;
					array[c][r] = (ch);
					printf("2 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
			case 3: //array[c+1][r];
				if ((c+1 <= 9) && (array[c+1][r] == '.')) {
					c += 1;
					ch++;
					array[c][r] = (ch);
					printf("3 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
			case 4: //array[c][r-1];
				if ((r-1 >= 0) && (array[c][r-1] == '.')) {
					r -= 1;
					ch++;
					array[c][r] = (ch);
					printf("4 - ch:%c c:%d r:%d\n", ch, c, r);
					break;
				}
		}

		if ((array[c-1][r] != '.') && (array[c][r+1] != '.') && (array[c+1][r] != '.') && (array[c][r-1] != '.')) {
			//printf("NO - ch:%c c:%d r:%d\n", ch, c, r);
			printf("*****YOU LOSE.*****\n");
			break;
		}

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

/*****SCHEMA*****
 * 1. Use srand and rand to generate random numbers
 * 2. Use remainder divided by four (X % 4) to determine cardinal direction of move
 * 3. Check that move won't go outside array; or, overwrite a position already assigned
 * 4. If either condition is violated, move elsewhere. If no moves, terminate
 */
