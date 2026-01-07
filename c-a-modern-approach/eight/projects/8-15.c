/******************************************
 * Name: 8-15.c.c
 * Purpose: Caesar Cipher
 * Author: amai-aijou
 * Date: Tue Jan  6 06:34:10 PM CST 2026
 ******************************************/

#include <stdio.h>

#define MAX 80
#define SIZE ((int) sizeof(array) / sizeof(array[0]))

int main(void) {

	int i = 0;
	char array[80] = {0};
	int shiftAmt = 0;

	char ch;

	printf("test: %c\n", array[0]);
	// Zero out the full array so it can become a  loop terminator
	for (i = 0; i < SIZE; i++) {
		array[i] = 0;
	}

	// Prompt user for message, read into array
	printf("Enter message to be encrypted: ");
	
	i = 0;
	while ((ch = getchar()) != '\n') {
		array[i] = ch;
		i++;
	}	

	printf("array[79]: %c\n", array[79]);

	// Prompt for shift amount
	printf("Enter shift amount (1-25): ");
	scanf("%d", shiftAmt);

	// Output final message
	printf("Encrypted message: ");

	for (i = 0; i < SIZE; i++) {
		
		// All unused trailing array elements will be a zero due to earlier loop; so, 0 is our early loop terminator
		// Note: Loop checks for two consecutive zeros, *just* in case someone really wanted to use one in their sentence!
		if (array[i] == 0 && array[i+1] == 0) {
			break;
		}	
		// Set ch to array element, simply for code visibility
		ch = array[i];

		printf("ch: %c\n", ch);

		// Capital letter cipher. Subtract 'A' (65), add shift amount, modulo 26, then add 'A' back in
		// This ensures the number is 0-25, so if Z is entered, it becomes: (90-65 + 1) % 26 + 65) == 0 == 'A'
		if (ch  >= 'A' && ch <= 'Z') {
			//65 == 'A', so
		ch  = ((ch - 65) + shiftAmt) %26 + 65;

		// Lower-case cipher. Needs separate formula as 'a-z' runs ASCII range '97-122'
		} else if (ch >= 'a' && ch <= 'z') {
			ch = ((ch - 97) + shiftAmt) %26 + 97;
		} 

		// All characters other than 'a-z', 'A-Z', and 00 will be printed as-is
		
		// Print current character
		printf("%c", ch);
	}

	return 0;
}

