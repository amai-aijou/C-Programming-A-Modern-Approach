/******************************************
 * Name: countdown.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Jan 11 04:51:40 PM CST 2026
 ******************************************/

#include <stdio.h>

void print_count(int n) {
	printf("T minus %2d and counting\n", n);
}

int main(void) {

	int i;

	for (i = 10; i > 0; i--) {
		print_count(i);
	}

	return 0;
}

