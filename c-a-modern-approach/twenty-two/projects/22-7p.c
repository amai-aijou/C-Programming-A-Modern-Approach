/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-7p.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue Sep  8 02:40:34 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100000

typedef unsigned char BYTE;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void compress_file(FILE *fp, char *filename);
void uncompress_file(FILE *fp, char *filename);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;
	char flag;

	/********** Error handling **********/
	if (argc != 3) {
		printf("Too many/few arguments!\nUsage: ./program -c filename\nUsage: /program -u filename\n");
		exit(EXIT_FAILURE);
	}

	if (strlen(argv[2]) > 100) {
		printf("Error: filename too long; terminating.\n", argv[2]);
		exit(EXIT_FAILURE);
	}	

	if ((fp = fopen(argv[2], "rb")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", argv[2]);
		exit(EXIT_FAILURE);
	} 


	/********** Choose Function **********/
	sscanf(argv[1], "-%c", &flag);

	switch (flag) {
		case 'c': compress_file(fp, argv[2]);
				  break;
		case 'u': uncompress_file(fp, argv[2]);
				  break;
		default:  printf("Error: invalid flag selected. Did you mean -c or -u?\n");
				  exit(EXIT_FAILURE);
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a)
void compress_file(FILE *fp, char *filename) {

	char encFilename[100];
	int ch, ch2, i = 0, count;

	// Append .rle to filename for saving encoded version
	strcpy(encFilename, filename);
	strcat(encFilename, ".rle");

	FILE *fp_rle;

	if ((fp_rle = fopen(encFilename, "w+b")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", filename);
		exit(EXIT_FAILURE);
	}

	for ( ; ;) {

		count = 0;

		ch = fgetc(fp);

		do {
			if (ch == EOF) {
				printf("Error: File appears empty!\n");
				return;
			}

			ch2 = fgetc(fp);
			count++;

			if (ch2 == EOF) {
				break;
			}

			if (ch == ch2) {
			}
		} while (ch == ch2 && count < 250);

		if (ch2 != EOF) {
			ungetc(ch2,fp);
		} 

		fputc(count,fp_rle);
		fputc(ch,fp_rle);

		if (ch2 == EOF) {
			return;
		}
	}
		
}

void uncompress_file(FILE *fp_rle, char *filename) {

	char unEncFilename[100];
	int encHexPair[2];
	int ch, i = 0, count; 
	int fileLen = strlen(filename);
	char *p;
	
	FILE *fp;

	if ((p = strstr(filename, ".rle")) == NULL) {
		printf("file %s does not appear to be an .rle; terminating.\n", filename);
		exit(EXIT_FAILURE);
	}

	
	if (p[4] == '\0') {
			strncpy(unEncFilename, filename, (p - filename));
			unEncFilename[p - filename] = '\0';
	} else {
		printf("file %s appears to be an .rle encoded into .rle. Not a good idea, but I guess I won't stop you?\n", filename);
			strncpy(unEncFilename, filename, (p - filename));
			unEncFilename[p - filename] = '\0';
	}

	if ((fp = fopen(unEncFilename, "w+b")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", unEncFilename);
		exit(EXIT_FAILURE);
	}

	for ( ; ; ) {

		count = 0;
		i = 0;

		while ((ch != EOF) && (i < 2)) {

			ch = fgetc(fp_rle);
			printf("DEBUG - ch[%d]:%.2X\n", i, ch);

			encHexPair[i] = ch;
			i++;
		}
		
		//printf("encHexPair: %.2X | %.2X\n", encHexPair[0], encHexPair[1]);

		if (ch != EOF && i < 2) {
			printf("ERROR: Unable to pull a full quartet. Ensure this is truly an .rle!\n");
			exit(EXIT_FAILURE);
		} else if (ch == EOF && i != 1) {
			printf("ERROR: Leftover data detected. Ensure this is truly an .rle!\n");
			exit(EXIT_FAILURE);
		} else if (ch == EOF && i == 0) {
			break;
		}
		
		if (ch == EOF) {
			break;
		}

		count = encHexPair[0];

		for (i = 0; i < count; i++) {

			fputc(encHexPair[1],fp);
		}
	}

}
