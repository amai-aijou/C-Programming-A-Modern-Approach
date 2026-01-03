/******************************************
 * Name: 8-8.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Jan  2 04:31:14 PM CST 2026
 ******************************************/

#include <stdio.h>

#define N 5
#define SIZE ((int) (sizeof(array) / sizeof(array[0][0])))

int main(void) {
	int array[N][N] = {0};
	int i = 0;
	int j = 0;
	double avg = 0;
	int rowSum = 0;
	int	colSum = 0;
	int highScore = 0;
	int lowScore = 1000;

	// Read the inputs for the two-dimensional array, one row at a time
	for (i = 0; i < N; i++) {
		printf("Enter grades for student #%d: ", (i+1));

		for (j = 0; j < N; j++) {
			scanf("%d", &array[i][j]);
		}
	}
	printf("\n");
	
	// Create Schema for Students
	printf("Student:\t ");
	for (i = 0; i < N; i++) {
		printf("#%-6d", i+1);
	}
	printf("\n");
	printf("---------------------------------------------------\n");

	// Student Totals
	printf("Total:\t    ");

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			rowSum += array[i][j];
		}

		printf("%7d", rowSum);	
		rowSum = 0;
	}
	printf("\n");

	// Student Average
	printf("Average:    ");

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			rowSum += array[i][j];
		}

		avg = rowSum / N;
		printf("%7.1f", avg);	
		rowSum = 0;
		avg = 0;
	}
	printf("\n");

	// Section separator
	printf("\n");


	// Create Schema for Quiz
	printf("Quiz:\t\t ");
	for (i = 0; i < N; i++) {
		printf("#%-6d", i+1);
	}
	printf("\n");
	printf("---------------------------------------------------\n");

	// Quiz Average
	printf("Average:    ");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			colSum += array[j][i];
		}
		avg = colSum / N;
		printf("%7.1f", avg);	
		colSum = 0;
		avg = 0;
	}
	printf("\n");

	// Quiz High Score
	printf("High Score: ");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (array[j][i] > highScore){
				highScore = array[j][i];
			}
		}

		printf("%7d", highScore);	
		highScore = 0;
	}
	printf("\n");

	// Quiz Low Score
	printf("Low Score:  ");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (array[j][i] < lowScore){
				lowScore = array[j][i];
			}
		}

		printf("%7d", lowScore);	
		lowScore = 1000;
	}
	printf("\n");

	return 0;
}

/********SCHEMA********
Student:		#1	#2	#3	#4	#5
Total			10	10	10	10	10
Average

Quiz:			#1	#2	#3	#4	#5
Average
High Score
Low Score

	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++) {
		printf("%6d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	*/
