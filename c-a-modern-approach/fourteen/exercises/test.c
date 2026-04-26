/******************************************
 * Name: 9-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 24 07:29:37 PM CST 2026
 ******************************************/

#include <stdio.h>

int compute_value(int x);

int main(void) {

	int x;

	printf("Please enter the value of x: ");
	scanf("%d", &x);

	printf("Formula: 3x^5 + 2x^4 - 5x^3 - x^2 + 7x-6\nAnswer: %d\n", compute_value(x));

	return 0;
}

int compute_value(int x) {

	int value;
	
	// 3x^5 + 2x^4 - 5x^3 - x^2 + 7x-6

	value = (((((3 * x + 2) * x - 5) * x -1) * x + 7) * x - 6);

	return value;
}
