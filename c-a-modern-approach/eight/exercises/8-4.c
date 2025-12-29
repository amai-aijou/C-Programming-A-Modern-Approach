/******************************************
 * Name: 8-3.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Dec 28 05:20:48 PM CST 2025
 ******************************************/

#include <stdio.h>

#include<stdbool.h>

int main(void) {
	int i;
	bool array[7] = {[0] = true, [6] = true};

	for (i = 0; i < 7; i++) {
		printf(" %d ", array[i]);
	}
	printf("\n");

	return 0;
}

