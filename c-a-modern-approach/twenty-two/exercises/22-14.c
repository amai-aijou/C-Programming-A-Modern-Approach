/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-14.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Aug 29 12:22:36 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 200

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *joe_fgets(char * restrict s, int n, FILE * restrict stream);
int joe_fputs(const char * restrict s, FILE * restrict stream);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char s[MAX_LEN];
	FILE *fp;
	char *filename = "test";

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Could not open file!\n");
		exit(EXIT_FAILURE);
	}

	printf("-------------------EXERCISE 22-13-------------------\n\n");
	printf( "Create your own versions of fgets and fputs!\n\n");
	
	joe_fgets(s, MAX_LEN, fp);

	joe_fputs(s, stdout);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

// Read a char from a stream
// check if it's EOF, \n, or \0; if so, break (unless EOF is 0)
// if not, add it to the array
// finish by adding \0 to ensure it's a string array
char *joe_fgets(char * restrict s, int n, FILE * restrict stream) {

	int ch;
	int i = 0;

	while (i < n - 1) {

		ch = getc(stream);


		if (ch == EOF) {
			if (i == 0) {
				return NULL;
			} else {
				break;
			}
		}

		if (ch == '\n') {
			s[i] = ch;
			i++;
			break;
		}

		s[i] = ch;
		i++;

	}

	s[i] = '\0';

	return s;
}

int joe_fputs(const char * restrict s, FILE * restrict stream) {

	char ch;
	int i;

	for (i = 0; (s[i] != '\0'); i++) {
		if (fputc(s[i], stream) == EOF) {
			printf("Error encountered, terminating!\n");
			return EOF;
		}
	}

	return 1;
}
