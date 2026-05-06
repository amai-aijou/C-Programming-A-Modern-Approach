/******************************************
 * Name: qsort.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Thu Jan 15 05:45:41 PM CST 2026
 ******************************************/

#include <stdio.h>
#include "quicksort.h"

#define N 10

int main(void) {

	int a[N], i;

	printf("Enter %d numbers to be sorted: ", N);

	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

		quicksort(a, 0, N - 1);

		printf("In sorted order: ");

		for (i = 0; i < N; i++) {
			printf("%d ", a[i]);
		}

		printf("\n");

		return 0;
}
