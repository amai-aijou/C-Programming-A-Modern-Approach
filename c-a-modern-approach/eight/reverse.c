/******************************************
 * Name: reverse.c.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Tue Nov 18 09:28:59 PM CST 2025
 ******************************************/

#include <stdio.h>

#define N 10

int main(void) {

	int a[N], i;

	printf("Enter %d numbers: ", N);

	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	printf("In reverse order:");
	for (i = N - 1; i >=0; i--)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
