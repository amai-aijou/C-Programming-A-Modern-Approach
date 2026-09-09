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

#define MAX_BUFFER 40

typedef unsigned char BYTE;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void clear_array(char *buffer);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;

	char buffer[MAX_BUFFER];
	int ch, i, n, count = 0, offset = 0;

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
	for (offset = 0; ; offset+= 10) {


		// Pull up to ten hex pairs and print them in Bytes column
		for (count = 0; count < 10; count++) {

			ch = fgetc(fp);
			buffer[count] = ch;

			if (ch == EOF) {
				break;
			} else if (count == 0) {
				// Print offset column
				printf("%6d  ", offset);
			}

			printf("%.2X ", ch);
		}
		
		// Adds empty space for any missing pairs
		for (i = count; i < 10; i++) {
			printf("   ");
		}
		printf("  ");

		// Prints characters column
		for (i = 0; i < (0 + count) ; i++) {

			if (isprint(buffer[i])) {
				printf("%c", buffer[i]);
			} else {
				printf(".");
			}
		}
		printf("\n");

		// Checks for end of file and terminates loop
		if (ch == EOF) {
			break;
		}

		clear_array(buffer);

		// Reprints table layout every one hundred lines
		if (offset != 0 && offset % 1000 == 0) {

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
void clear_array(char *buffer) {

	int i;

	for (i = 0; i < MAX_BUFFER; i++) {
		buffer[i] = 0;
	}	
}
