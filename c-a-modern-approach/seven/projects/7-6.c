/******************************************
 * Name: 7-6.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Sep 13 03:11:26 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	

	printf("Values of: \n");
	printf("Size of int: %lu\n",(unsigned long) sizeof(int));
	printf("Size of short: %hd\n", (short) sizeof(short));
	printf("Size of long: %ld\n", (long) sizeof(long));
	printf("Size of float: %f\n", (float) sizeof(float));
	printf("Size of double: %f\n", (double) sizeof(double));
	printf("Size of longdouble:	%Lf\n",(long double) sizeof(long double));

	return 0;
}

