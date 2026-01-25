/******************************************
 * Name: doubler.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 24 07:37:22 PM CST 2026
 ******************************************/

#include <stdio.h>

int main(void) {

	int x;
	int days = 0;
	long long dollars = 0;

	printf("Enter number of dollars to double: ");
	scanf("%d", &dollars);

	printf("Enter a number of days: ");
	scanf("%d", &days);

	for (x = 0; x < days; x++) {

		if (x == 0) {
			continue;
		}

		dollars *= 2;
	}	

	printf("Total: %ld\n", dollars);

	return 0;
}

