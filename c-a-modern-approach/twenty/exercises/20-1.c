/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue Jul 21 08:09:22 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	unsigned short i, j, k;

	printf("-------------------EXERCISE 20-1-------------------\n\n");
	printf(COLOR_MAGENTA "Q. What is the output of each fragment containing unsigned short variables?\n\n");

	printf(COLOR_CYAN  "(a) i = 8; j = 9;\n"
					   "    printf(\"%%d\", i >> 1 + j >> 1);\n");
	printf(COLOR_RESET " Guess: 1000 >> (1 + 9) >> 1\n"
			           "        1000 >> 10 >> 1\n"
					   "        0 >> 1\n"
					   "        0\n"
					   "Output: ");
	i = 8; j = 9;
	printf("%d\n\n", i >> 1 + j >> 1);


	printf(COLOR_CYAN  "(b) i = 1;\n"
					   "    printf(\"%%d\", i & ~i);\n");
	printf(COLOR_RESET " Guess: 0001 & 1000\n"
			           "        0000\n"
	                   "Output: ");
	i = 1;
	printf("%d\n\n", i & ~i);
	printf(COLOR_RESET "");


	printf(COLOR_CYAN  "(c) i = 2; j = 1; k = 0;\n"
					   "    printf(\"%%d\", ~i & j ^ k);\n");
	printf(COLOR_RESET " Guess: 1101 & 0001 ^ 0000\n"
					   "        0001 ^ 0000\n" 
					   "        0001\n"
					   "Output: ");
	i = 2; j = 1; k = 0;
	printf("%d\n\n", ~i & j ^ k);


	printf(COLOR_CYAN  "(d) i = 7; j = 8; k = 9;"
					   "    printf(\"%%d\", i ^ j & k);");
	printf(COLOR_RESET " Guess: 0111 ^ 1000 & 1001\n"
			           "        0111 ^ 1000\n"
					   "        1111\n"
					   "Output: ");
	i = 7; j = 8; k = 9;
	printf("%d\n\n", i ^ j & k);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

*/
