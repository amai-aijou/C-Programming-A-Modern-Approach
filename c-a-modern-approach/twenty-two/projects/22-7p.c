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

#define BUFFER_SIZE 1000

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

	if ((fp = fopen(argv[2], "rb")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	if (argc != 3) {
		printf("Too many/few arguments!\nUsage: ./program -c filename\nUsage: /program -u filename\n\n");
	}

	sscanf(argv[1], "-%c", &flag);

	switch (flag) {
		case 'c': compress_file(fp, argv[2]);
				  break;
		case 'u': uncompress_file(fp, argv[2]);
				  break;
	}

}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void compress_file(FILE *fp, char *filename) {

	int ch;
	char buffer[BUFFER_SIZE];
	char encFilename[100];
	int i = 0;
	int n = sizeof(buffer);
	int count;

	// Append .rle to filename for saving encoded version
	strcpy(encFilename, filename);
	strcat(encFilename, ".rle");

	FILE *fp_rle;

	if ((fp_rle = fopen(encFilename, "w+b")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", filename);
		exit(EXIT_FAILURE);
	}

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

		fprintf(fp_rle, "%02d %.2X ", count, buffer[i]);
	}

}

void uncompress_file(FILE *fp, char *filename) {

}
