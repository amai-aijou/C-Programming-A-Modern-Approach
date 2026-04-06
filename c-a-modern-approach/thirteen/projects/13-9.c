/******************************************
 * Name: 13-9.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep 21 03:15:17 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(void) {

	int vowels;
	char ch;
	char buffer[100];

	// Ask user for a sentence, then use getchar() to parse vowels
	printf("Enter a sentence: ");

	if (fgets(buffer, sizeof(buffer), stdin)) {
	}
		const char *sentence = buffer;

	// Print number of vowels, then exit
	printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence) {

	int vowels = 0;
	const char *p;

	for (p = sentence; *p != '\0'; p++) {

		// Change to upper-case to cut required case statements in half
		switch (toupper(*p)) {
			case 'A':	case 'E':	case 'I':	case 'O':	case 'U':
				vowels++;
		}
	}

	return vowels;
}
