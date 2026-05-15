/******************************************
 * Name: 9-18.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 08:25:43 PM CST 2026
 ******************************************/

#include <stdio.h>

int gcd(int m, int n);

int gcd_new(int m, int n);

int main(void) {
	int m, n, x;

	printf("Enter two numbers: ");
	scanf("%d %d", &m, &n);
  
	if (n > m) {
		x = m;
		m = n;
		n = x;
	}

	printf("The GCD is: %d\n", gcd(m,n));
	printf("The GCD (new) is: %d\n", gcd_new(m,n));

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

int gcd_new(int m, int n) {

	int remainder = 0;

	if (n == 0) {
		return m;
	} else {
		remainder = m % n;
		m = n;
		n = remainder;
		gcd(n,(m%n));
	}
}
