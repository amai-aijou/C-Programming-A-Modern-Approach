/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 18-13.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jun 29 06:16:29 PM CDT 2026
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

#define PI 3.14159
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-1-------------------\n\n");

	char c = 65;
	double d = 2 * PI;
	double angles[] = {0, PI / 2, PI, 3 * PI / 2};

	printf(COLOR_MAGENTA "Q. Determine the legality of each declaration:\n");

	printf(COLOR_MAGENTA "(a) char c = 65;\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "characters and integers can be freely exchanged. 65 = A.\n\n");

	printf(COLOR_MAGENTA "(b) static int i = 5, j = i * i;;\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Illegal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "Constants cannot be used for variables or switch cases.\n\n");

	printf(COLOR_MAGENTA "(c) double d = 2 * PI;;\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "Macros are resolved to numeric values before compiling. 2 * 3.14159 is perfectly valid!\n");
	printf(				 "           double d: %lf\n\n", d);

	printf(COLOR_MAGENTA "(a) double angles[] = {0, PI / 2, PI, 3 * PI / 2};\n"
		   COLOR_CYAN    "  Note: Please assume that the following Declaration is in use: " COLOR_RESET "#declare PI = 3.14159\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "as with c, this is perfectly normal. 3.14159 / 2 is a completely valid way to initialize an array element.\n");
	printf(              "           double angles[3]: %lf\n\n", angles[3]);
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
