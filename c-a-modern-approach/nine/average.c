/******************************************
 * Name: average.c
 * Purpose: Computes pairwise averages of three numbers
 * Author: amai-aijou
 * Date: Sun Jan 11 04:42:34 PM CST 2026
 ******************************************/

#include <stdio.h>

double average(double a, double b) {
	return (a + b) / 2;
}

int main(void) {
	
	double x, y, z;

	printf("Enter three numbers: ");
	scanf("%lf%lf%lf", &x, &y, &z);
	printf("Average of %g and %g: %g\n", x, y, average(x, y));
	printf("Average of %g and %g: %g\n", y, z, average(y, z));
	printf("Average of %g and %g: %g\n", x, z, average(x, z));

	return 0;
}

