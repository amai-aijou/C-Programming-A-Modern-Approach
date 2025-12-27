/******************************************
 * Name: test.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Dec 20 05:41:39 PM CST 2025
 ******************************************/

#include <stdio.h>

int main(void) {
	int x = 10;

//	while ( --x > 0) {
	for ( x=10 ; x > 0 ; x--) {
		printf("Value of X: %d \n", x);
	}
	printf("\n");

	return 0;
}

