/******************************************
 * Name: 13-11.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Nov  8 04:51:21 PM CST 2025
 ******************************************/

#include <stdio.h>

double compute_average_word_length(const char *sentence);
void read_line(char *name, int n); 

int main(void) {

	float chCount = 0;
	float wCount = 1;
	float avgCount = 0;
	char ch;
	const char sentence[100] = "this is a test";

	//printf("Enter a sentence: ");


/*
	while ((ch = getchar()) != '\n') {

		if (ch != ' ' && ch != '\n') {
			chCount++;
		}

		if (ch == ' ') {	
		wCount++;
		}
		// Iterate Word count; run through empty loop to iterate through spaces
	}

	// Calculate average count by dividing character count by word count
	avgCount = chCount / wCount;

	printf("Average word length: %.1f\n", avgCount);
*/
	printf("Average word length: %.1f\n", compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence) {

	const char *p;
	float chCount = 0;
	float wCount = 1;

	for (p = sentence; *p != '\0'; p++) {
		if (*p != ' ' && *p != '\n') {
			chCount++;
		}

		if (*p == ' ') {
			wCount++;
		}
	}

	return chCount / wCount;

}

void read_line(char *name, int n) {

	char ch;
	int i = 0;
	
	while ((ch = getchar()) != '\n') {
		if (i < n) {
			name[i++] = ch;
		}
	}

	name[i] = '\0';
}
