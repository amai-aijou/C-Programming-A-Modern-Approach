/******************************************
 * Name: 9-10.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 17 08:45:37 PM CST 2026
 ******************************************/

#include <stdio.h>

int largest(int a[], int n);
int average(int a[], int n);
int numPos(int a[], int n);

int main(void) {
	int n, x;

	// Request size for array
	printf("Please give a size for array a: ");
	scanf("%d", &n);

	// Initialize arrray
	int a[n];

	// Fill array with incrementing values
	for (x = 0; x < n; x++) {
		a[x] = (x + 1);
	}

	printf("Largest: %d\n", largest(a, n));

	printf("Average: %d\n", average(a, n));

	printf("Number of Positive: %d\n", numPos(a, n));

	return 0;
}

int largest(int a[], int n) {
	int max, x;

	for (x = 0; x < n; x++) {
		if (a[x] > max) {
			max = a[x];
		}	
	}

	return (max);
}

int average(int a[], int n) {

	int avg, x;

	for (x = 0; x < n; x++) {
		avg += a[x];
	}

	avg /= n;

	return (avg);
}

int numPos(int a[], int n) {

	int pos = 0, x;

	for (x = 0; x < n; x++) {
		if (a[x] >= 0) {
			pos++;
		}
	}

	return (pos);
}
