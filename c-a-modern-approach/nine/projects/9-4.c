/******************************************
 * Name: 9-4.c
 * Purpose: Anagram tester
 * Author: amai-aijou
 * Date: Wed Jan  7 09:03:09 PM CST 2026
 ******************************************/

#include <stdio.h>
#include <ctype.h> // necessary for tolower() and toalpha()
#include <stdbool.h>

// ALPHA is size of array dimension; SIZE is size of all array dimensions
#define ALPHA 26

// Function Prototypes
void read_word(int counts[ALPHA]);
bool equal_array(int counts1[ALPHA], int counts2[ALPHA]);

// Main Function
int main(void) {

	int counts1[ALPHA] = {0};
	int counts2[ALPHA] = {0};
	int i;
	int sum = 0;

	// Ask for first word, then read word in through read_words() function
	printf("Enter first word: ");
	read_word(counts1);

	// Ask for first word, then read word in through read_words() function
	printf("Enter second word: ");
	read_word(counts2);

	// Check if arrays are equal
	sum = equal_array(counts1,counts2);

	if (sum > 0 ) {
		printf("The words are anagrams.\n");
	}

	if (sum == 0) {
		printf("The words are not anagrams.\n");
	}

	return 0;
}

void read_word(int counts[ALPHA]) {

	char ch;

	// Loop through input; for each char, increment array position for each alpha letter by 1
	while ((ch = getchar()) != '\n') {
		//Confirm character is a letter
		if (isalpha(ch)) {
			
			// Increment array; tolower() ensures ASCII codes match, because 97 ('a') is then subtracted to ensure array is 0-25
			// ex: ch = 'b' = "98-97" = "0"; thus, array[0] would be updated 
			counts[((tolower(ch))-97)]++;
		}
	}
}

bool equal_array(int counts1[ALPHA], int counts2[ALPHA]) {

	int x;

	for (x = 0; x < ALPHA; x++) {

		if (counts1[x] != counts2[x]) {
			return false;
		}
	}

	return true;

}

/*****DEBUGGING*****
printf("test: %d\n", counts[(ch-97)]);
*/
