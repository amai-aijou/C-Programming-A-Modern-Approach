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
	bool digit_repeated[10] = {false};
	bool repeats = false;
	long n;
	int i;

	printf("Enter a number: ");
	scanf("%ld", &n);

	// Clever loop to read all digits without needing to iterate through them as characters
	//  "n % 10" reads the last digit (since all other digits cleanly fit into 10)
	//  "n / 10" removes the right-most digit (all other digits are divisible by 10, and remainder is dropped in programming)
	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			digit_repeated[digit] = true;
			repeats = true;
		}
		digit_seen[digit] = true;
		n /= 10;
	}

	if (repeats) {
		printf("Repeated digit/s: ");
		for (i = 0; i < 10; i++) {
			if (digit_repeated[i]) {
				printf("%d ", i);
			}
		}
			printf("\n");
	} else {
		printf("No repeated digits\n");

	}

	return 0;
}

