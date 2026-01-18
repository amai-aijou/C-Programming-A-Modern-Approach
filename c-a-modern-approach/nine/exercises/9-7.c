/******************************************
 * Name: 9-7test.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 17 07:56:15 PM CST 2026
 ******************************************/

#include <stdio.h>

int f(int a, int b);

int main(void) {

	int a = 0, b = 0;
	int i;
	double x;

	printf("Enter two numbers to add together: ");
	scanf("%d %d", &a, &b);

	printf("Sum: %d\n", f(a, b));

	i = f(83, 12);
	printf("(a) %d\n", i);

	x = f(83, 12);
	printf("(b) %lf\n", x);

	i = f(3.15, 9.28);
	printf("(c) %d\n", i);

	x = f(3.15, 9.28);
	printf("(d) %lf\n", x);

	f(83, 12);
	printf("(e) %d\n", f(83, 12));

	return 0;
}

int f(int a, int b) {

	printf("Value of a: %d\n", a);
	printf("Value of b: %d\n", b);

	return  (a + b);
}
