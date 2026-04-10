/******************************************
 * Name: 8-15.c.c
 * Purpose: Caesar Cipher
 * Author: amai-aijou
 * Date: Tue Jan  6 06:34:10 PM CST 2026
 ******************************************/

#include <stdio.h>

#define MAX 80

// Prototypes
void encrypt(char *message, int shiftAmt);
void read_line(char *message, int n);
void zero_array(char *message);
void print_array(char *message);

int main(void) {

	char message[80] = {'0'};
	int n = 80;
	int shiftAmt = 0;

	// Prompt user for message, read into array
	printf("Enter message to be encrypted: ");
	
	read_line(message, 80);

	printf("DEBUG - You entered:\n");
	print_array(message);

	// Prompt for shift amount
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shiftAmt);

	encrypt(message, shiftAmt);

	printf("\nTo decode, enter: %d\n", (26 - shiftAmt));

	return 0;
}

void encrypt(char *message, int shiftAmt) {

	int i;
	char ch;

	// Output final message
	printf("Encrypted message: ");

	for (i = 0; i < MAX; i++) {
		
		// All unused trailing array elements will be a zero due to earlier loop; so, 0 is our early loop terminator
		// Note: Loop checks for two consecutive zeros, *just* in case someone really wanted to use one in their sentence!
		if (message[i] == 0 && message[i+1] == 0) {
			break;
		}	
		// Set ch to array element, simply for code visibility
		ch = message[i];


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
}

void read_line(char *message, int n) {

	char ch;
	int i = 0;
	
	while ((ch = getchar()) != '\n') {

		if (i < n) {
			message[i++] = ch;
		}
	}

	message[i] = '\0';
}

void zero_array(char *message) {

	int i;

	// Zero out the full array so it can become a  loop terminator
	for (i = 0; i < MAX; i++) {
		message[i] = 0;
	}
}

void print_array(char *message) {

	int i;

	for (i = 0; i < MAX; i++) {
		printf("%c", message[i]);
	}
	printf("\n");

}
