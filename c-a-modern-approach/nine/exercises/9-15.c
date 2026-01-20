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

	double medianNum = 0;

	if (x <= y)
		if (y <= z) 
			medianNum = y;
		else if (x <= z) 
			medianNum = z;
		else 
			medianNum = x;
	
	if (z <= y)
		medianNum = y;
	else if (x <= z)
		medianNum = x;
	else
		medianNum = z;

	return (medianNum);
}

/*-------------------------

if (1 <= 2)
	if (2 <= 3)
		medianNum = 2;
	else if (1 <= 3)
		medianNum = 3;
	else
		medianNum = 1;

? 2 1 ?

if (3 <= 2)
	medianNum = 2;
if (1 <= 3)
	medianNum = 1;
else
	medianNum = 3;
	
*/
