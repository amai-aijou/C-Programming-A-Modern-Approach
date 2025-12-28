/******************************************
 * Name: repdigit.c
 * Purpose: Checks for repeated digits
 * Author: amai-aijou
 * Date: Sat Dec 27 06:25:55 PM CST 2025
 ******************************************/

//C99 method of adding bool logic
//#include <stdbool.h>
#include <stdio.h>

//Standard C method of adding bool logic
#define true 1
#define false 0
#define bool int

int main(void) {
	bool digit_seen[10] = {false};
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit])
			break;
		digit_seen[digit] = true;
		n /= 10;
	}

	if (n > 0)
		printf("Repeated digit\n");
	else
		printf("No repeated digit\n");

	return 0;
}

