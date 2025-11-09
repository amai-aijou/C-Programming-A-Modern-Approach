/******************************************
 * Name: 7-14.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Nov  8 08:10:31 PM CST 2025
 ******************************************/

#include <stdio.h>
#include <math.h>

int main(void) {

	double input;
	double x;
	double y = 1;
	double avg = 1;
	double product;

	printf("Enter a positive number: ");
	scanf("%lf", &input);
	x = input;

	do {
		y = avg;
		product = x / y;
		avg = (y + product) / 2;

	} while ((fabs(y - avg)) > (.00001 * y));

	printf("Square root: %f\n", y);

	return 0;
}

/*
 * Storage for various DEBUG statements
		printf("DEBUG | Value of x: %f\n", x);
		printf("DEBUG | Value of y: %f\n", y);
		printf("DEBUG | Value of product: %f\n", product);
		printf("DEBUG | Value of avg: %f\n", avg);
		printf("DEBUG | Value of fabs(y-avg) %f\n", (fabs(y - avg)));
*/
