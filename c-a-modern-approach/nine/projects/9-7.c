/******************************************
 * Name: 9-7.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Jan 25 07:50:49 PM CST 2026
 ******************************************/

#include <stdio.h>

int power_old(int x, int n);
int power(int x, int n);

int main(void) {

	int x, n;

	printf("Enter a number, and the power to take it to: ");
	scanf("%d %d", &x, &n);

	printf("Answer: %d\n", power(x, n));

	return 0;
}

int power_old(int x, int n) {

	if (n == 0) {
		return 1;
	} else {
		return x * power_old(x, n - 1);
	}
}

int power(int x, int n) {

	if (n == 0) {
		return 1;
	}

	// if n is even, use (x^n/2)^2, which in C writes out as: (x^n/2) * (x^n/2)
	if (n % 2 == 0) {

		return power(x, n/2) * power(x, n/2); 

	// If n is odd, use x * x^n-1
	} else {

		return	x * power(x, n-1);
	}
}

/*********SCRATCH PAPER********
 * even: (x^n/2) * x
 *  odd: x * x^n-1
 *
 * 
 *
 *****DEBUGGING STATEMENTS*****
 * printf("even | n:%d | x:%d | add x^2\n", n, x);
 *
 */

