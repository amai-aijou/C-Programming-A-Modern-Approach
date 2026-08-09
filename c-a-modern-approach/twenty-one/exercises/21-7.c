/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 21-7.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Aug  9 03:58:45 PM CDT 2026
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

	printf("-------------------EXERCISE 21-7-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Which header do each of these functions live in?\n\n");

	printf(COLOR_CYAN    "    unsigned int n;\n"
			             "    n &= n - 1;\n\n");

	printf(COLOR_MAGENTA "(a) A function determining the current day of week\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<time.h>\n"
			             "  function: the localtime() function\n\n");

	printf(COLOR_MAGENTA "(b) A function testing if a char is a digit\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<ctype.h>\n"
			             "  function: the isdigit() function\n\n");

	printf(COLOR_MAGENTA "(c) A macro giving the largest unsigned int value\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<limits.h>\n"
			             "     macro: the UINT_MAX macro\n\n");
	
	printf(COLOR_MAGENTA "(d) A function rounding a floating-point number to the next-highest int\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<math.h>\n"
			             "  function: the ceil() function\n\n");

	printf(COLOR_MAGENTA "(e) A macro specifying the number of bits in a char\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<limits.h>\n"
			             "     macro: the CHAR_BIT macro\n\n");

	printf(COLOR_MAGENTA "(f) A macro specifying the # of significant digits in a double value\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<float.h>\n"
			             "     macro: the DBL_DIG macro\n\n");

	printf(COLOR_MAGENTA "(g) A function searching a string for a specific char\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<string.h>\n"
			             "  function: the strchr() function\n\n");

	printf(COLOR_MAGENTA "(h) A function opening a file for reading\n");
	printf(COLOR_CYAN    "  #include: " COLOR_RESET "<stdio.h>\n"
			             "  function: the fopen() function\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
