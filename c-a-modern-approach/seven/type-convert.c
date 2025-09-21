/******************************************
 * Name: exercises.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Sep  1 03:10:23 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	char c = '\1';
	short s = 2;
	int i = -3;
	long m = 5;
	float f = 6.5f;
	double d = 7.5;

	printf("(a) c * i = %d\n", c * i);
	printf("(b) s + m = %ld\n", s + m);
	printf("(c) f / c = %f\n", f / c );
	printf("(d) d / s = %f\n", d / s );
	printf("(e) f - d = %f\n", f - d);
	printf("(f) (int) f = %d \n", (int) f);

	return 0;
}

