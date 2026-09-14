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

	char buffer[BUFFER_SIZE], encFilename[100];
	int ch, ch2, i = 0, n = sizeof(buffer), count;

	// Append .rle to filename for saving encoded version
	strcpy(encFilename, filename);
	strcat(encFilename, ".rle");

	FILE *fp_rle;

	if ((fp_rle = fopen(encFilename, "w+b")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", filename);
		exit(EXIT_FAILURE);
	}

/*
	while ((ch = fgetc(fp)) != EOF) {
		buffer[i] = ch;
		i++;
	}
	buffer[i] = '\0';

	for (i = 0; i < n && buffer[i] != '\0'; i++) {

		count = 1;

		while (buffer[i] == buffer[i+1]) {
			i++;
			count++;
		}

		// Output compressed count byte and data byte to file
		fputc(count,fp_rle);
		fputc(buffer[i],fp_rle);

	}
*/
	for ( ; ;) {

		count = 0;

		do {
			ch = fgetc(fp);
			if (ch == EOF) {
				printf("Error: File appears empty!\n");
				return;
			}

			ch2 = fgetc(fp);
			count++;

			if (ch2 == EOF) {
				break;
			}
		} while (ch == ch2);

		if (ch2 != EOF) {
			ungetc(ch2,fp);
		} 

		for (i = 0; i < count; i++) {
			fputc(count,fp_rle);
			fputc(ch,fp_rle);
		}

		if (ch2 == EOF) {
			return;
		}
	}
		
}

void uncompress_file(FILE *fp_rle, char *filename) {

	char buffer[BUFFER_SIZE], unEncFilename[100];
	int encHexPair[2];
	int ch, i = 0, n = sizeof(buffer), count; 
	int fileLen = strlen(filename);
	char *p;
	int debug, output;
	
	FILE *fp;

	printf("DEBUG - filename %s\n", filename);
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
	printf("DEBUG - unEncFilename %s\n", unEncFilename);

	for ( ; ; ) {

		count = 0;
		i = 0;

		/*
		ch = fgetc(fp_rle);
		printf("DEBUG - ch (0): %c\n", ch);
		encHexPair[0] = ch;
		ch = fgetc(fp_rle);
		printf("DEBUG - ch (1): %c\n", ch);
		encHexPair[1] = ch;
		*/

		while (((ch = fgetc(fp_rle)) != EOF) && (i < 2)) {

			printf("DEBUG - ch[%d:%c\n", i, ch);

			encHexPair[i] = ch;
			i++;
		}
		

		printf("encHexPair: %c | %c\n", encHexPair[0], encHexPair[1]);

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

//		printf("DEBUG - count: %d\n", count);

		for (i = 0; i < count; i++) {

			output = encHexPair[1];
//			printf("DEBUG - output: %d\n", output);
			fprintf(fp, "%c",output);
		}
	}

}
