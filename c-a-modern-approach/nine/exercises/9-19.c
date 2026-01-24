/******************************************
 * Name: 8-19.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Jan 23 07:58:38 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h>

void pb(int n);

int main(void) {

	int n;

	printf("Please enter a number: ");
	scanf("%d", &n);

	printf("This weird function returns:\n");

	pb(n);

	printf("\n");

	return 0;
}

void pb(int n) {

	if (n != 0) {
		pb(n / 2);
		putchar('0' + n % 2);
	}
}

/*
 * n = 5
 *
 * First, Recursion:
 *
 * pb(5/2)
 * pb(2/2)
 * pb(1/2)
 * pb(0)
 *
 * Then, 'unwind', by starting with the putchar statement in the lowest function
 * 0 <--This is ignored because of the "if" statement
 * 1
 * 0
 * 1
 *
 *Final output: 101
 *
 * it is a binary generator!
 *
 */


