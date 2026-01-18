/******************************************
 * Name: 9-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 17 07:10:00 PM CST 2026
 ******************************************/

#include <stdio.h>

int digit (int n, int k);

int main(void) {

	int n = 0, k = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("Enter the digit to pull: ");
	scanf("%d", &k);

	printf("Value: %d\n", digit(n, k));

	return 0;
}

int digit (int n, int k) {

	int x = 0;

	for (x = 1; x < k; x++) {
		n /= 10;
	}

	n %= 10;

	return (n);
}
