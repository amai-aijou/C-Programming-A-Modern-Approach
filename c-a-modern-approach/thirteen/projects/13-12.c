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
	int first = 1;
	char sentence[MAX_WORDS][MAX_LENGTH] = {0};
	char ch;
	char punct = '.';

	printf("Enter a sentence: ");

	for (words = 0; words < MAX_WORDS; words++) {
		
		j = 0;

		while ((ch = getchar()) != '?' && ch != '!' && ch != '.')  {
			if (ch == ' ' || j == (MAX_LENGTH - 1)) {
				break;
			}
			sentence[words][j++] = ch;
		}

		punct = ch;
		sentence[words][j] = '\0';

		if (ch == '?' || ch == '!' || ch == '.') {
			break;
		}
		printf("end of for loop - ch: %c\n", ch);
	}

	printf("Reversal of sentence: ");

	for ( ; words >= 0; words--) {
		
		if (first == 0) {
			printf(" ");	
		}
		printf("%s", sentence[words]);
		first = 0;
	}

	printf("%c\n", punct);

	return 0;
}


/************************DEBUG********************

	printf("while loop - ch: %c\n", ch);
	printf("sentence[%d][%d]: %c\n", words, j-1, sentence[words][j-1]);

**************************************************/
