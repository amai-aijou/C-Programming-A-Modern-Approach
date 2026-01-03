/******************************************
 * Name: 8-7.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Jan  2 04:31:14 PM CST 2026
 ******************************************/

#include <stdio.h>

#define N 5
#define SIZE ((int) (sizeof(array) / sizeof(array[0][0])))

int main(void) {
	int array[N][N] = {0};
	int i, j;
	int rowSum = 0;
	int	colSum = 0;

	// Read the inputs for the two-dimensional array, one row at a time
	for (i = 0; i < N; i++) {
		printf("Enter row %d: ", (i+1));

		for (j = 0; j < N; j++) {
			scanf("%d", &array[i][j]);
		}
	}

	// Debugging
	//printf("DEBUGGING - array[0][0]: %d\n", array[0][0]);
				
	// Determine the sum of the rows, then print
	printf("Row totals: ");

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			rowSum += array[i][j];
		}

		printf("%d ", rowSum);	
		rowSum = 0;
	}
	printf("\n");

	// Determine the sum of the columns, then print
	printf("Column totals: ");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			colSum += array[j][i];
		}

		printf("%d ", colSum);	
		colSum = 0;
	}
	printf("\n");

	return 0;
}
