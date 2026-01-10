/******************************************
 * Name: 8-17.c
 * Purpose: Magic square
 * Author: amai-aijou
 * Date: Thu Jan  8 06:29:58 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h>

#define SIZE ((int) sizeof(array) / sizeof(array[0][0]))

int main(void) {
	int i, j;
	int n; // n^2 Dictates square size
	int row, col;

	printf("This program creates a magic square of a specified size.\n"
			"The size must be an odd number between 1 and 99.\n");

	printf("Enter size of magic square: ");
	scanf("%d", &n);

	int array[n][n];	
	// Zero out array before use (this allows us to discern empty elements
	for (i = 0; i < n; i++) {

			printf("values of n: %d\n", n);
		for (j = 0; j < n; j++) {
			array[i][j] = 0;
		//	printf("array[%d][%d]: %d\n", i, j, array[i][j]);
		//	printf("values of n: %d\n", n);
		}
	}

	// Place first number in middle of row 0
	col = (n / 2);
	row = 0;

	printf("TEST - row:%d | col:%d | num:1\n", row, col);

	// Build magic square
	for (i = 0; i < SIZE; i++) {
		
		if (array[row][col] == 0) {
			array[row][col] = (i + 1);
		} else {
			row = row + 1;

			array[row][col] = (i + 1);
		}		

		row = n - (i % n) - 1;
		col = (col + 1) % n;

		printf("TEST - row:%d | col:%d | num:%d\n", row, col, (i+2));

	}
	
	printf("TEST - array[0][0]: %d\n", array[0][0]);	

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
 ****************/
