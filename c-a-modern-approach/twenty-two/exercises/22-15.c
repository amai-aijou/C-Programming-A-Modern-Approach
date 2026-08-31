/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-15.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Aug 30 06:47:55 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

#define RECORD_SIZE 64

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	FILE *fp;
	char *filename = "test.bin";
	char ch;
	long int n = 3;

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Can't open file!\n");
		exit(EXIT_FAILURE);
	}


	printf("-------------------EXERCISE 22-15-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Write calls of fseek that perform file-positioning operations against test.bin, a binary file arranged in 64-byte records\n\n");

	printf(COLOR_MAGENTA "(a) Move to the beginning of record n (let's say n is 3)\n");
	fseek(fp, (RECORD_SIZE * n), SEEK_SET);
	printf(COLOR_CYAN    " Output: " COLOR_RESET "%c\n\n", fgetc(fp)); 

	printf(COLOR_MAGENTA "(b) Move to the beginning of the last 64-byte record\n");
	fseek(fp, (RECORD_SIZE * -1L), SEEK_END);
	printf(COLOR_CYAN    " Output: " COLOR_RESET "%c\n\n", fgetc(fp)); 

	printf(COLOR_MAGENTA "(c) Move forward one 64-byte record\n");
	fseek(fp, (RECORD_SIZE * 1L), SEEK_CUR);
	printf(COLOR_CYAN    " Output: " COLOR_RESET "%c\n\n", fgetc(fp)); 
	
	printf(COLOR_MAGENTA "(d) Move backwards two 64-byte records\n");
	fseek(fp, (RECORD_SIZE * -2L), SEEK_CUR);
	printf(COLOR_CYAN    " Output: " COLOR_RESET "%c\n\n", fgetc(fp)); 

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
