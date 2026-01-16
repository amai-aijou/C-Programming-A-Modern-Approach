/******************************************
 * Name: 9-3.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 08:25:43 PM CST 2026
 ******************************************/

#include <stdio.h>

int gcd(int m, int n);

int main(void) {
	int m, n, x;

	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);

	if (n > m) {
		x = m;
		m = n;
		n = m;
	}

	printf("The GCD is: %d\n", gcd(m,n));

	return 0;

}

int gcd(int m, int n) {

	int remainder;

	while (n != 0) {
		remainder = m % n;
		m = n;
		n = remainder;
	}

	return(m);

}

