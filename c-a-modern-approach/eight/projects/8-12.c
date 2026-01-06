/******************************************
 * Name: 8-12.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep  7 07:47:13 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

#define ALPHA 26

int main(void) {
	
	int num;
	int score = 0;
	char ch;

	int values[ALPHA] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

	printf("Enter a word: ");

	while ((ch = getchar()) != '\n') {

	score += values[(toupper(ch))-65];
	
	/* Old code
	while ((ch = getchar()) != '\n') {
		switch (ch = toupper(ch)) {
			case 'A': case 'E': case 'I': case 'L': case 'N':
			case 'O': case 'R': case 'S': case 'T': case 'U':
				// Handles AEILNORSTU: 1 point
				score += 1;
				break;	
			case 'D': case 'G':
				// Handles DG - 2 points
				score += 2;
				break;	
			case 'B': case 'C': case 'M': case 'P': 
				// Handles BCMP - 3 points
				score += 3;
				break;	
			case 'F': case 'H': case 'V': case 'W': case 'Y':
				// Handles FHVWY - 4 points
				score += 4;
				break;	
			case 'K':
				// Handles K - 5 points
				score += 5;
				break;	
			case 'J': case 'X':
				// Handles JX - 8 points
				score += 8;
				break;	
			case 'Q': case 'Z':
				// Handles QZ - 10 points
				score += 10;
				break;	
			default:
				// I was going to make 1pt be default, but figured it'd be more
				// readable to list them out...but the book itself does that, so...
				// I just wanted it known that I did at least think of that =P
				printf("This isn't a letter at all!\n");
		}
		*/
	}

	printf("Scrabble value: %d\n", score);
	return 0;	
}

