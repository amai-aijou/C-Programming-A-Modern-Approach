/******************************************
 * Name: length.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Fri Aug 29 08:39:51 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void) {
	
	char ch;
	int len = 0;

	printf("Enter a message: ");
	ch = getchar();
	while (ch != '\n') {
		len++;
		ch = getchar();
	}
	printf("Your message was %d character(s) long.\n", len);

	return 0;
}
