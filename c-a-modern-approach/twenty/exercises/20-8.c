/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-8.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jul 27 01:52:36 PM CDT 2026
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
unsigned int f(unsigned int i, int m, int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n = 4;
	int i = 15;
	int m = 5;

	unsigned int a = ~(~0 << n);
	unsigned int b = i >> (m + 1 - n);

	printf("-------------------EXERCISE 20-8-------------------\n\n");
	printf(COLOR_MAGENTA "unsigned int f(unsigned int i, int m, int n) {\n"
			             "    return (i >> (m + 1 - n)) & ~(~0 << n);"
			             "}\n\n");

	printf(COLOR_CYAN    "(a)What is ~(~0 << n)?\n");
	printf(COLOR_RESET   "     Guess: 0xFFFFFFFF, then adds n zeros at right, then flips it. End result = n 1's at right\n");
	printf(COLOR_RESET   "   right half of equation: %d\n", a);
	printf(COLOR_RESET   "   left half of equation: %d\n\n", b);

	printf(COLOR_CYAN    "(b) What is the purpose of this function?\n"
		   COLOR_CYAN    "    Purpose: " COLOR_RESET "This function selects n bits from binary i, in a field m bits long\n"
                         "             The left half moves the bits you want to view to the very right of the integer\n"
                         "             The right half makes a mask of 1s n digits long, so only the bits you want to view\n"
						 "               are ultimately viewable in the end.\n"
		   COLOR_CYAN 	 "    End result: " COLOR_RESET "n digits, starting at m, viewable at the right of i\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
unsigned int f(unsigned int i, int m, int n) {

	return (i >> (m + 1 - n)) & ~(~0 << n);
}
