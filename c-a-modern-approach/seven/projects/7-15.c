/******************************************
 * Name: 7-15.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Nov  9 05:24:30 PM CST 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	int x;
	int input;
	int factorial;

	// Request positive integer, store in variable x
	printf("Enter a positive integer: ");
	scanf("%d", &input);

	x = input;

	for (factorial = x; --x; x > 0) {
		factorial *= x;	
	}
	
	printf("Factorial of %d: %d\n", input, factorial );

	return 0;
}

