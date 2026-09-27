/******************************************
 * Name: 22-14.c (prev. 8-15.c)
 * Purpose: Caesar Cipher
 * Author: amai-aijou
 * Date: Tue Jan  6 06:34:10 PM CST 2026
 ******************************************/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void encrypt_file(FILE *fp, FILE *fpEnc);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

int main(void) {

	//22-14
	char filename[100], encFilename[100 + 4];

	FILE *fp, *fpEnc;

	printf("Enter name of file to be encrypted: ");
	scanf("%s", &filename);

	strcpy(encFilename, filename);
	strcat(encFilename, ".enc");

	// Open original file
	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("Error: Could not open %s for reading.\n", filename);
		exit(EXIT_FAILURE);
	}

	// Open encrypted file
	if ((fpEnc = fopen(encFilename, "wb")) == NULL) {
		printf("Error: Could not open %s for writing.\n", encFilename);
		exit(EXIT_FAILURE);
	}

	encrypt_file(fp, fpEnc);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

void encrypt_file(FILE *fp, FILE *fpEnc) {

	int shiftAmt;
	char ch;

	// Prompt for shift amount
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shiftAmt);

	printf("Encrypted message: ");

	while ((ch = fgetc(fp)) != EOF) {

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
		fputc(ch,fpEnc);

		// Output copy of encrypted message
		printf("%c", ch);
	}


	printf("\nTo decode, enter: %d\n", (26 - shiftAmt));

}
