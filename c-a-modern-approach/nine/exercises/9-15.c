/******************************************
 * Name: 9-15.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan 19 09:05:56 PM CST 2026
 ******************************************/

#include <stdio.h>

double median(double x, double y, double z);

int main(void) {

	double x, y, z;
	
	printf("Please enter three numbers: ");
	scanf("%lf %lf %lf", &x, &y, &z);

	printf("The middle number of the three is: %lf\n", median(x,y,z));

	return 0;
}

double median(double x, double y, double z) {

	double med = 0;

	if (x <= y) {
		if (y <= z) med = y;
		else if (x <= z) med = z;
		else med = x;
	}
	else {
	if (z <= y) med = y;
	else if (x <= z)  med = x;
	else med = z;
	}

	return med;
}

