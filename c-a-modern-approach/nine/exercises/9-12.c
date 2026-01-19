/******************************************
 * Name: 9-12.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Jan 18 08:36:45 PM CST 2026
 ******************************************/

#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void) {

	int x, n;
	int y = 0;

	printf("Please provide a size for the array: ");
	scanf("%d", &n);

	double a[n];
	double b[n];

	for (x = 0; x < n; x++) {
		a[x] = x;
		printf("a[%d]: %lf\n", x, a[x]);
	}

	for (x = n; x > 0; x--) {
		b[y] = x;
		printf("b[%d]: %lf\n", y, b[y]);
		y++;
	}

	printf("Inner product: %lf\n", inner_product(a,b,n));
	
	return 0;
}

double inner_product(double a[], double b[], int n) {

	int x;
	double product = 0;

	for (x = 0; x < n; x++) {
		product += (a[x] * b[x]);
	}

	return product;
}
