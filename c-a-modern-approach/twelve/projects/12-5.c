/******************************************
 * Name: 12-5.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Mon Jan  5 07:52:07 PM CST 2026
 ******************************************/

#include <stdio.h>

#define MAX 100
#define SIZE ((int) sizeof(a) / sizeof(a[0]))

int main(void) {

	int i;
	char a[MAX];
	char ch;
	char punct = '.';
	char *currentPos;
	char *lastPos;
	char *p = a;
	int n = 0;

	printf("Enter a sentence: ");

	while ((ch = getchar()) != '\n') {
		*(p + n) = ch;

		if ((ch == '?') || (ch == '!') || (ch == '.')) {
			punct = ch;
			lastPos = (p + n);
			break;
		}
		n++;
	}	


	//DEBUG: print array
	for (p = a; p < a+n; p++) {
		printf("%c", *p);
	}
	printf("%c\n", punct);
	printf("n: %d\n---------------\n", n);

	printf("Reversal of sentence: ");

	for (p = a + (n-1); p >= a; p--) {
		if (*p == ' ' | p == a) {
			currentPos = (p);

			if (p != a) {
				p++;
			}
			
			while (p < lastPos) {
				printf("%c", *p);
				p++;
			}

			if (currentPos != a) {
				printf(" ");
			}

			p = currentPos;
			lastPos = currentPos;


		}	
	}

	printf("%c\n", punct);

	return 0;
}
/****OLD******
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

****OLD******/

/*****SCHEMA*****
oh I am?
01234567

punct: 7
end: 7
4-end

am Ioh?
*****************/
