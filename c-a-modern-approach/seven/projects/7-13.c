/******************************************
 * Name: 7-13.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sat Nov  8 04:51:21 PM CST 2025
 ******************************************/

#include <stdio.h>

int main(void) {

	float chCount = 0;
	float wCount = 1;
	float avgCount = 0;
	char ch;

	printf("Enter a sentence: ");

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

	return 0;
}
