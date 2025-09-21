/******************************************
 * Name: 7-10.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep 21 03:15:17 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

int main(void) {

	int vowels;
	char ch;

	// Ask user for a sentence, then use getchar() to parse vowels
	printf("Enter a sentence: ");

	//Iterate through input one char at a time
	while ((ch = getchar()) != '\n') {
	
		// Change to upper-case to cut required case statements in half
		switch (toupper(ch)) {
			case 'A':	case 'E':	case 'I':	case 'O':	case 'U':
				vowels++;
		
		}

	} 

	// Print number of vowels, then exit
	printf("Your sentence contains %d vowels.\n", vowels);

	return 0;
}

