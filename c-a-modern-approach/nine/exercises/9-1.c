/******************************************
 * Name: 9-1.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 08:09:20 PM CST 2026
 ******************************************/

#include <stdio.h>

double triangle_area(double base, double height);

int main(void) {
	double base, height;

	printf("Enter base and height: ");
	scanf("%lf %lf", &base, &height);

	printf("The product is: %lf", triangle_area(base, height));

	return 0;
}

double triangle_area(double base, double height) {
	double product;
	
	product = base * height;

	return (product / 2);
}
