/******************************************
 * Name: 9-2.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 08:17:54 PM CST 2026
 ******************************************/

#include <stdio.h>

int check(int x, int y,int n);

int main(void) {
	int x, y, n;

	printf("Check whether two numbers are both positive, and less than \"n-1\"\n");

	printf("Value of first number: ");
	scanf("%d", &x);

	printf("Value of second number: ");
	scanf("%d", &y);

	printf("Value of n: ");
	scanf("%d", &n);

	if (check(x,y,n) == 1) {
		printf("Both numbers are positive, and fall within the range!\n");
	} else {
		printf("Failure.\n");
	}

	return 0;
}

int check(int x, int y, int n) {
	if ((x > 0) && (x < (n-1))) {
		if ((y > 0) && (y < (n-1))) {
			return 1;
		}
	}
	return 0;
}
