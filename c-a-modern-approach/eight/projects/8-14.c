/******************************************
 * Name: 8-14.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan  5 07:52:07 PM CST 2026
 ******************************************/

#include <stdio.h>

#define MAX 100
#define SIZE ((int) sizeof(array) / sizeof(array[0]))

int main(void) {

	int i;
	char array[MAX];
	char ch;
	char punct = '.';
	int currentPos;
	int lastPos;

	printf("Enter a sentence: ");

	for (i = 0; i < SIZE; i++) {
		// Read characters into array one at a time
		array[i] = (ch = getchar());

		// Terminate array when end of sentence is reached
		if (array[i] == '?' || array[i] == '!' || array[i] == '.') {
			punct = array[i];
			lastPos = i;	
			break;		
		}
	}

	printf("Reversal of sentence: ");

	// Reversal of sentence iterates from lastPos to zero
	for (i = lastPos; i >= 0; i--) {

		// When a space is encountered (or at beginning), begin logic to print
		if (array[i] == ' ' || i == 0) {

			// Add one so the space is omitted
			currentPos = (i + 1);
			
			// As there is no space for first word, subtract one so you don't lose the first letter!
			if (i == 0) {
				currentPos -= 1;
			}

			// Once current word has been found, beginning is marked with currentPod, end with last Pos, and printed!
			while (currentPos < lastPos) {	
				printf("%c", array[currentPos]);
				currentPos++;
			}
			// Reset lastPos to beginning of word so the cycle can repeat
			lastPos = i;

			// Print a space between words (unless at the first word)
			if (i != 0) {
			printf(" ");
			}
		}
	}

	//Print the punctuation for the sentence to finish it (and newline so terminal cursor doesn't look weird)
	printf("%c\n", punct);

	return 0;
}

/*****SCHEMA*****
oh I am?
01234567

punct: 7
end: 7
4-end

am Ioh?
*****************/
