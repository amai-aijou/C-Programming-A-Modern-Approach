/******************************************
 * Name: 9-11.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Jan 18 06:47:06 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float compute_GPA(char grades[], int n);

int main(void) {
	int n, x;
	int min = 65;
	int randChars[5] = {65, 66, 67, 68, 70};

	printf("Please provide a size for the array: ");
	scanf("%d", &n);

	char grades[n];
	
	srand((unsigned) time(NULL));

	for (x = 0; x < n; x++) {
		grades[x] = randChars[(rand() % 5)];
	}

	printf("grades[0]: ");
	for (x = 0; x < n; x++) {
		printf("%c", grades[x]);
	}
	printf("\n");

	printf("Average: %.1f\n", compute_GPA(grades, n));

	return 0;
}



float compute_GPA(char grades[], int n) {

	int x;
	float avg = 0;

	for (x = 0; x < n; x++) {
		switch (grades[x]) {
			case 'A':
				avg += 4.0;
				break;
			case 'B':
				avg += 3.0;
				break;
			case 'C':
				avg += 2.0;
				break;
			case 'D':
				avg += 1.0;
				break;
			case 'F':
				avg += 0.0;
				break;
		}
	}

	return (avg /= n);
}
