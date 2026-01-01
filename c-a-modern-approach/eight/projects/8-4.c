/******************************************
 * Name: 8-4.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Dec 27 04:35:09 PM CST 2025
 ******************************************/

#include <stdio.h>

#define N 10
#define SIZE ((int) (sizeof(a) / sizeof(a[i])))

int main(void) {
	int a[N], i;
	
	printf("Enter %d numbers: ", N);
	for (i = 0; i < SIZE ; i++) {
		scanf("%d", &a[i]);
	}
		

	printf("In reverse order:");
	for (i = N - 1; i >= 0; i--)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
