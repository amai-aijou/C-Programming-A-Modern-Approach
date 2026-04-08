/******************************************
 * Name: 13-12.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan  5 07:52:07 PM CST 2026
 ******************************************/

#include <stdio.h>

#define MAX_WORDS 30
#define MAX_LENGTH 20
#define SIZE ((int) sizeof(array) / sizeof(array[0]))

int main(void) {

	int words, j;
	char sentence[MAX_WORDS][MAX_LENGTH];
	char ch;
	char punct = '.';

	printf("Enter a sentence: ");

	for (words = 0; words < MAX_WORDS; words++) {
		
		j = 0;
		while ((ch = getchar()) != '?' || ch != '!' || ch != '.')  {
			if (ch == ' ' || j == (MAX_LENGTH - 1)) {
				break;
			}

			sentence[words][j++] = ch;
			printf("sentence[%d][%d]: %c\n", words, j-1, sentence[words][j-1]);
		}
		punct = ch;
		sentence[words][j] = '\0';

		if (ch == '?' || ch == '!' || ch == '.') {
			break;
		}
	}

	printf("Reversal of sentence: ");

	for ( ; words > 0; words--) {
		printf("%s", sentence[words]);
	}

	printf("%c\n", punct);

	return 0;
}

/****************OLD CODE********************

		for (j = 0; j < (MAX_WORDS - 1); j++) {
			array[i][j] = ch
		}
	}

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

****************OLD CODE********************/

/*****SCHEMA*****
oh I am?
01234567

punct: 7
end: 7
4-end

am Ioh?
*****************/
