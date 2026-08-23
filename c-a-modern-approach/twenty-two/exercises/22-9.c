/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-9.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Aug 23 11:29:22 AM CDT 2026
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

	int a,b,c,d;

	printf("-------------------EXERCISE 22-9-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Which are valid ways to read a single character from stdin?\n\n");

	// NOTE: Uncomment the three lines associated with the answer you want to test (so you don't get conflicting results!)

	printf(COLOR_MAGENTA "(a) getch()\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Illegal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "There is no gcc macro for getch()\n");
//	printf(COLOR_CYAN    "Enter char: " COLOR_RESET);
//	a = getchar();
//	printf(COLOR_CYAN    "    Output: " COLOR_RESET "%c\n\n", a);

	printf(COLOR_MAGENTA "(b) getchar()\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "Pulls in one character. Normal way to do things!\n\n");
//	printf(COLOR_CYAN    "Enter char: " COLOR_RESET);
//	b = getchar();
//	printf(COLOR_CYAN    "    Output: " COLOR_RESET "%c\n\n", b);

	printf(COLOR_MAGENTA "(b) getc(stdin)\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "getc() allows for an input to be selected, and only stores the first char *if* you use a char type\n");
//	printf(COLOR_CYAN    "Enter char: " COLOR_RESET);
//	c = getc(stdin);
//	printf(COLOR_CYAN    "    Output: " COLOR_RESET "%c\n\n", c);

	printf(COLOR_MAGENTA "(b) fgetc(stdin)\n"
		   COLOR_CYAN    "    Status: " COLOR_RESET "Legal\n"
		   COLOR_CYAN    "    Reason: " COLOR_RESET "It's just getc(), but guaranteed to be a function instead of a macro.\n\n");
	printf(COLOR_CYAN    "Enter char: " COLOR_RESET);
	d = fgetc(stdin);
	printf(COLOR_CYAN    "    Output: " COLOR_RESET "%c\n\n", d);
	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
