/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-4p.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Sep  4 08:50:34 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 100

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int char_count(FILE *fp);
int word_count(FILE *fp);
int line_count(FILE *fp);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	FILE *fp;
	int i;
	char ch;

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("ERROR: could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("note: includes whitespace and newline chars!\n");

	printf("(a) Char count: %d \n", char_count(fp));

	printf("(b) Word count: %d \n", word_count(fp));

	printf("(c) Line count: %d \n", line_count(fp));

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int char_count(FILE *fp) {

	char ch;
	int count = 0;

	rewind(fp);

	while ((ch = fgetc(fp)) != EOF) {

		count++;
	}

	return count;
}

int word_count(FILE *fp) {

	char ch;
	int count = 0;

	rewind(fp);

	while ((ch = fgetc(fp)) != EOF) {

		if (ch != ' ' && ch != '\n') {
			while ((ch = fgetc(fp)) != ' ' && ch != EOF && ch != '\n') {

			}

			count++;
		}
	}

	return count;
}

int line_count(FILE *fp) {

	char ch;
	int count = 0;
	char buffer[MAX_LINE_SIZE+2];

	rewind(fp);

	while ((fgets(buffer, MAX_LINE_SIZE, fp)) != NULL) {
		count++;

	}

	return count;
}
