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
	int digit_count[10] = {0};
	long n;
	int i;

	printf("Enter a number: ");
	scanf("%ld", &n);

	// Clever loop to read all digits without needing to iterate through them as characters
	//  "n % 10" reads the last digit (since all other digits cleanly fit into 10)
	//  "n / 10" removes the right-most digit (all other digits are divisible by 10, and remainder is dropped in programming)
	while (n > 0) {
		digit = n % 10;
			digit_count[digit] += 1 ;
		digit_seen[digit] = true;
		n /= 10;
	}

		printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\n");
		printf("Occurrences:\t");
		for (i = 0; i < 10; i++) {
				printf("%d ", digit_count[i]);
			}
			printf("\n");

	return 0;
}

