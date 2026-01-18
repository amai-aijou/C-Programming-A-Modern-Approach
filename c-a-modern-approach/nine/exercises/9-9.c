/******************************************
 * Name: 9-9.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Jan 17 08:38:09 PM CST 2026
 ******************************************/

#include <stdio.h>

void swap(int a, int b);

int main(void) {

	int i = 1, j = 2;

	swap(i, j);
	
	printf("guess!:i = 1, j = 2 (swap's output is simply thrown away!\n");
	printf("answer:i = %d, j = %d\n", i, j);
	return 0;
}

void swap(int a, int b) {
	
	int temp = a;
	a = b;
	b = temp;
}

// temp = 1;
// a = 2;
// b = 1;
