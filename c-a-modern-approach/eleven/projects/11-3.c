/******************************************
 * Name: prog3.c
 * Purpose: 
 * Author: jolson
 * Date: Sun Jun  8 04:43:13 PM CDT 2025
 ******************************************/

#include <stdio.h>

// Prototypes
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void) {

	int numerator, denominator;
	int reduced_numerator, reduced_denominator;
	int num, denom, remainder;

	printf("Enter a fraction: ");
	scanf("%d/%d", &numerator, &denominator);


	if (denominator == 0) {
		printf("dividing by zero!?! stop, you'll kill us all!! you'll k-\n.\n..");
		printf("...u-urgh..w-...why...the fool...the damn fool... \n");
		return 1;
	}
	
	reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);


	printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

	return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {

	int tempNum, tempDenom, remainder;

	tempNum = numerator;
	tempDenom = denominator;

	while (tempNum != 0) {
		remainder = tempDenom % tempNum;
		tempDenom = tempNum;
		tempNum= remainder;	
			
	}

	*reduced_numerator   = numerator   / tempDenom;
	*reduced_denominator = denominator / tempDenom;
}



/*
 * Example of logic flow:
 * 12/16
 *
 * num = 12
 * denom = 16
 *
 * while:
 * remainder = 16 % 12 = 4;
 * denom = 12
 * num = 4
 *
 * 4/12
 * remainder = 12 % 4 = 0
 * denom = 4
 * num = 0
 *
 * nnum = 12 / 4 = 3
 * ndenom = 16 / 4 = 4
 * 
 */
