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
	int row, col, prevRow, prevCol;
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

	// Number of moves equal to number of squares
	// Count starts at 2 as first number already placed
	moves = n * n;
	count = 2;

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

		// Check if square to be written is zero
		if (array[row][col] == 0) {
			array[row][col] = count;
		
		// If square to be written is not zero, restore to backup, then move one row "down" (increase number by one)
		} else {

			row = prevRow;
			col = prevCol;

			// Subtract fromm row; loop back as needed
			if (row + 1 >= n) {
				row = 0;
			} else {
				row += 1;
			}	

			array[row][col] = count;
		}

		count++;
		moves--;

	}

/*
	for (i = 0; i < n; i++) {
		row = n - (i % n) - 1;
		col = (col + 1) % n;
		array[row][col] = i;
		*/

	/**************SCRAPPED - ALGORITHM VERSION CAN'T TRAVERSE********
	// Build square
	for (i = 0; i < 5; i++) {

		prevRow = row;
		prevCol = col;

		row = n - (i % n) - 1;i
		col = (col + 1) % n;


		valid = false;
		row = n - (i % n) - 1;
		col = (col + 1) % n;

		if (array[row][col] == 0) {
			valid = true;
		}

		if (valid == false) {
			
		}

			row = n - (i % n) - 1;
			col = (col + 1) % n;

		array[row][col] = i+2;

	printf("TEST - row:%d | col:%d | num:%d\n", row, col, i+2);
	}
	*/

	// Print final square
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}



/*****SCHEMA*****
 * ^ 1 > 1 x 5; V 1; ^1 > 1 x5;
 * you go a row up and a column up until you hit an already-populated square;
 * then, go down one row and start again
 *
 * array[0][(n / 2) + 1] = 1;
 * [0-1][3-1]
 *
 * row:
 * 0 
 *
 * col:
 * (3 + 1) % n = 4
 * (4 +1) % 5 = 0
 * 0 +1 % 5 = 1
 * 1 +1 % 5 = 2
 * 2 +1 % 5 = 3 (TAKEN)
 * 3 + 1 % 5 = 4

		row = n - row + 1;
		5 - (0 % 5) + 1 = 4
		5 - 1+1 = 3
		5 - 2+1 = 2
		5 - 3+1 = 1
		5 - 4+1 = 0
		5 - (5 % 5)+1 = 4
		printf("TEST - row:%d | col:%d | num:%d\n", row, col, count);
 ****************/
