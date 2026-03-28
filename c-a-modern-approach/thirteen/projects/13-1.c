/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 13-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Mar 27 08:55:09 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <string.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int enter_word(char word[], char smallest_word[], char largest_word[]);
void compare_words(char word[], char smallest_word[], char largest_word[]);
void zero_array(char word[], int n);
void print_array(char word[], int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char word[100] = {0};
	char smallest_word[100] = {0};
	char largest_word[100] = {0};
	int numWords = 0;
	int wordLength = 0;

	do {

		wordLength = enter_word(word, smallest_word, largest_word);
		numWords++;

	} while (wordLength != 4);

	printf("You entered %d words.\n", numWords);
	printf("Smallest word: %s\nLargest word: %s\n", smallest_word, largest_word);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int enter_word(char word[], char smallest_word[], char largest_word[]) {

	char ch;
	char *p = word;

	printf("Enter word: ");

	while ((ch = getchar()) != '\n') {
		*p++ = ch;
	}
	*p = '\0';

	compare_words(word, smallest_word, largest_word);

	return strlen(word);
}

void compare_words(char word[], char smallest_word[], char largest_word[]) {

	// If this is the first word, it is automatically the smallest and largest
	if (strlen(smallest_word) == 0) {
		strcpy(smallest_word, word);
		strcpy(largest_word, word);
	}

	if (strcmp(word, smallest_word) < 0) {
		strcpy(smallest_word, word);
	}


	if (strcmp(word, largest_word) > 0) {

		strcpy(largest_word, word);
	}
}

void zero_array(char word[], int n) {

	char *p;

	for (p = word; *word; word++) {
		*p = '\0';
	}
}

void print_array(char word[], int n) {

	char *p;

	for (p = word; *word; word++) {
		printf("%c", *p);
	}
	printf("\n");
}


/*******************DEBUG STATEMENTS*********************
 
	printf("strcmp (smallest): %d\n", strcmp(word, smallest_word));
		printf("word is smaller than current smallest.\n");
		printf("new smallest: %s\n", smallest_word);

	printf("strcmp (largest): %d\n", strcmp(word, largest_word));
		printf("word is larger than current largest.\n");
		printf("new smallest: %s\n", largest_word);

****************************/
