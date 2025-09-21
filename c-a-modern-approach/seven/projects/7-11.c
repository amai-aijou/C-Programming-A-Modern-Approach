/******************************************
 * Name: 7-11.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep 21 03:25:01 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

int main(void) {

	char ch;
	char first;

	printf("Enter a first and last name: ");
	
	first = getchar();

	while ((ch = getchar()) != ' ') {
		// Blank loop to run through first name
	}
	while ((ch = getchar()) == ' ') {
			// blank loop to run through spaces
	}

	do {
		putchar(ch); 
	}
	while ((ch = getchar()) != '\n'); 

	printf(", %c.\n", first);

	return 0;
}

