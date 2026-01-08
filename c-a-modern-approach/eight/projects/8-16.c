/******************************************
 * Name: 8-16.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Wed Jan  7 09:03:09 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h> // necessary for tolower() and toalpha()

// ALPHA is size of array dimension; SIZE is size of all array dimensions
#define ALPHA 26
#define SIZE ((int) sizeof(array) / sizeof(array[0]))

int main(void) {

	int array[ALPHA] = {0};
	char ch;
	int i;
	int sum = 0;

	// Zero out array before starting
	for (i=0; i < SIZE; i++) {
		array[i] = 0;
	}

	// Ask for first word
	printf("Enter first word: ");
	
	// Loop through input; for each char, increment array position for each alpha letter by 1
	while ((ch = getchar()) != '\n') {
		//Confirm character is a letter
		if (isalpha(ch)) {
			
			// Increment array; tolower() ensures ASCII codes match, because 97 ('a') is then subtracted to ensure array is 0-25
			// ex: ch = 'b' = "98-97" = "0"; thus, array[0] would be updated 
			array[((tolower(ch))-97)]++;
		}
	}

	// Ask for second word
	printf("Enter second word: ");

	// Loop through input; for each char, decrement array position for each alpha letter by 1
	while ((ch = getchar()) != '\n') {
		//Confirm character is a letter
		if (isalpha(ch)) {
			
			// Decrement array; tolower() ensures ASCII codes match, because 97 ('a') is then subtracted to ensure array is 0-25
			// ex: ch = 'b' = "98-97" = "0"; thus, array[0] would be updated 
			array[((tolower(ch))-97)]--;
		}
	}

	for (i=0; i < SIZE; i++) {
		sum += array[i];
	}

	if (sum == 0) {
		printf("The words are anagrams.\n");
	}

	if (sum > 0 ) {
		printf("The words are not anagrams.\n");
	}

	return 0;
}

/*****DEBUGGING*****
printf("test: %d\n", array[(ch-97)]);
*/
