
/******************************************
 * Name: sum2.c
 * Purpose: 
 * Author: jolson
 * Date: Sat Jun 21 04:36:45 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	double n, sum = 0;

	printf("This program sums a series of doubles.\n");
	printf("Enter doubles (0 to terminate): ");

	scanf("%lf", &n);

	while (n != 0) {
		sum += n;
		scanf("%lf", &n);
	}

	printf("The sum is: %f\n", sum);

	return 0;
}

