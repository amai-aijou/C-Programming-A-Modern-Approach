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

	if (argc != 3) {
		printf("Too many/few arguments!\nUsage: ./program -c filename\nUsage: /program -u filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "rb")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", argv[2]);
		exit(EXIT_FAILURE);
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
// (a)
void compress_file(FILE *fp, char *filename) {

	char buffer[BUFFER_SIZE], encFilename[100];
	int ch, i = 0, n = sizeof(buffer), count;

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

		fprintf(fp_rle, "%02d%.2X", count, buffer[i]);
	}

}

void uncompress_file(FILE *fp, char *filename) {

	char buffer[BUFFER_SIZE], unEncFilename[100];
	int ch, i = 0, n = sizeof(buffer), count; 
	int fileLen = strlen(filename);
	char *p = strstr(filename, ".rle");

	FILE *fp_rle;
	
	if (p[4] == '\0') {
			strncpy(unEncFilename, filename, (p - filename));
			unEncFilename[p - filename] = '\0';
	}

	if ((fp_rle = fopen(unEncFilename, "w+b")) == NULL) {
		printf("Error: Could not open file %s; terminating.\n", filename);
		exit(EXIT_FAILURE);
	}

}
