/******************************************
 * Name: 8-5.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Dec 28 05:55:49 PM CST 2025
 ******************************************/

#include <stdio.h>

int main(void) {
	int fib_numbers[40] = {0, 1};
	int i;

	printf("%d ", fib_numbers[0]);
	printf("%d ", fib_numbers[1]);

	for (i = 2; i < 40; i++) {
		fib_numbers[i] = (fib_numbers[i-1] + fib_numbers[i-2]);
		printf("%d ", fib_numbers[i]);
	}

	printf("\n");

	return 0;
}

