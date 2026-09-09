/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-6p.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Sep  6 05:48:35 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER 50

typedef unsigned char BYTE;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void clear_array(char *lineBytes);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;

	char lineBytes[MAX_BUFFER];
	int ch, i, offset = 0;

	// Error Checking: Too few/many arguments
	if (argc != 2) {
		printf("Too few/many arguments!\nUsage: ./program filename\n");
		exit(EXIT_FAILURE);
	}

	// Error Checking: Could not open file
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		printf("Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Prints table layout
	printf("Contents of %s:\n\n", argv[1]);
	printf("Offset\t\t   Bytes\t       Characters\n");
	printf("------  -----------------------------  ----------\n");

	// Main loop for reading file. Ends when EOF is read in
	for (; ; ) {

		// Print offset column
		printf("%6d  ", offset);

		// Pull up to ten hex pairs and print them in Bytes column
		for (i = 0; i < 10; i++) {

			ch = fgetc(fp);
			lineBytes[i] = ch;

			if (ch == EOF) {
				break;
			} else {
				ch = (BYTE) ch;
			}

			printf("%.2X ", ch);
		}
		
		// Adds empty space for any missing pairs
		for (; i < 10; i++) {
			printf("   ");
		}
		printf("  ");

		// Prints characters column
		for (i = 0; i < 10; i++) {

			if (isprint(lineBytes[i])) {

				printf("%c", lineBytes[i]);
			} else {
				printf(".");
			}
		}
		printf("\n");

		offset += 10;

		// Checks for end of file and terminates loop
		if (ch == EOF) {
			break;
		}

		clear_array(lineBytes);

		// Reprints table layout every one hundred lines
		if (offset % 1000 == 0) {

			printf("Offset\t\t   Bytes\t       Characters\n");
			printf("------  -----------------------------  ----------\n");
		}
	}

	fclose(fp);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void clear_array(char *lineBytes) {

	int i;

	for (i = 0; i < MAX_BUFFER; i++) {
		lineBytes[i] = 0;
	}	
}
