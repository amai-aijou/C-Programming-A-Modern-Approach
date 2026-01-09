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
	int array[n][n];	
	int row, col;

	printf("This program creates a magic square of a specified size.\n"
			"The size must be an odd number between 1 and 99.\n");

	printf("Enter size of magic square: ");
	scanf("%d", &n);

	// Zero out array before use (this allows us to discern empty elements
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			array[i][j] = 0;
		}
	}

	// Place first number in middle of row 0
	col = (n / 2) + 1;

	// Build magic square
	for (i = 0; i < SIZE; i++) {
		
	}
	array[row][col] = (i + 1);

	row -= 1;
	col += 1;
	

	printf("array[0][0]: %d\n", array[0][0]);


	return 0;
}



/*****SCHEMA*****
 * ^ 1 > 1 x 5; V 1; ^1 > 1 x5;
 * you go a row up and a column up until you hit an already-populated square;
 * then, go down one row and start again
	array[0][(n / 2) + 1] = 1;
