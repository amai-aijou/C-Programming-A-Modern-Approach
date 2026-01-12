/******************************************
 * Name: 8-17.c
 * Purpose: Magic square
 * Author: amai-aijou
 * Date: Thu Jan  8 06:29:58 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE ((int) sizeof(array) / sizeof(array[0][0]))

int main(void) {
	int i, j;
	int n; // n*n = square size
	int row, col, nextRow, nextCol;
	int moves, count;

	printf("This program creates a magic square of a specified size.\n"
			"The size must be an odd number between 1 and 99.\n");

	printf("Enter size of magic square: ");
	scanf("%d", &n);

	// C99: Initialize array (must occur after scanf provides value to n)
	int array[n][n];	

	// Zero out array before use (this allows us to discern empty elements
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			array[i][j] = 0;
		}
	}

	// Place first number in middle of row 0
	col = (n / 2);
	row = 0;
	array[row][col] = (1);

	// Number of moves equal to total squares (minus one as first moved already occurred)
	// Count starts at 2 as first number already placed
	moves = (n * n) - 1;
	count = 2;

/*****IMPROVED PROGRAM (MODULAR ARITHMETIC)*****/

	while ( moves > 0) {

		nextRow = (row - 1 + n) % n;
		nextCol = (col + 1) % n;

		if (array[nextRow][nextCol] != 0) {
			row = (row + 1) % n;
		} else {
			row = nextRow;
			col = nextCol;
		}

			array[row][col] = count;
			count++;
			moves--;
	}
/**************ORIGINAL PROGRAM*****************
	// Iterate through remaining values
	while ( moves > 0) {

		// Store previous values as backup
		prevRow = row;
		prevCol = col;
		
		// Subtract one from row; if row would go negative, loop back to highest value
		if ((row - 1) < 0) {
			row = n -1;
		} else {
			row -= 1;
		}

		// Add one to column; if column would exceed highest value, loop back to zero
		if (col + 1 >= n) {
			col = 0;
		} else {
			col += 1;
		}

		// If square is already written (non-zero): restore to backup, then move one row "down" (increase number by one)
		if (array[row][col] != 0) {

			// Restore previous values
			row = prevRow;
			col = prevCol;

			// Subtract fromm row; loop back as needed
			if (row + 1 >= n) {
				row = 0;
			} else {
				row += 1;
			}	

		}

		// Print row, increment count, decrement moves
		array[row][col] = count;	
		count++;
		moves--;
	}
***********************************************/
	// Print final square
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/******DEBUGGING******
 *
 * printf("TEST - row:%d | col:%d | num:%d\n", row, col, count);
 *
 ********************/
