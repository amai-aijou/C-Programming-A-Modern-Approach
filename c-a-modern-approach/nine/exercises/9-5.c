/******************************************
 * Name: 9-5.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 17 06:47:36 PM CST 2026
 ******************************************/

#include <stdio.h>

int num_digits(int n);

int main(void) {

	int num = 0;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Number of digits: %d\n", num_digits(num));

	return 0;
}

int num_digits(int n) {
	int digits = 0;

	while (n > 0) {
		n = n / 10;
		digits++;
	}

	return (digits);
}
