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

	int i = 0;
	char name[30];

	// Zero out array so only currently-utilized values are printed when iterating
	for (i = 0; i < 30; i++) {
		name[i] = 0;
	}	

	printf("Enter a first and last name: ");
	
	// Save first initial in "first" variable
	first = getchar();

	// Run through first name and space/s, not saving any
	while ((ch = getchar()) != ' ') {
		// Blank loop to run through first name
	}
	while ((ch = getchar()) == ' ') {
		// blank loop to run through spaces
	}

	// Reset i after use in previous loop
	i = 0;

	// save last name and read into array name[]
	do {
		name[i] = (ch);
		i++;
	}
	while ((ch = getchar()) != '\n'); 

	printf("You entered the name: ");

	// Iterate array to print name
	for (i = 0; i < 30; i++) {

		// Array has zeros in all unused values; if found, exit (if their name has a zero in it...well, that's weird!)
		if (name[i] == 0) {
			break;
		}

		printf("%c", name[i]);
	}

	printf(", %c.\n", first);

	return 0;
}

