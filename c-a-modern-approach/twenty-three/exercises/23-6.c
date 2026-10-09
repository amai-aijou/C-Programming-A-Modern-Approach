/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 23-6.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Oct  8 07:31:43 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

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

	printf("-------------------EXERCISE 23-6-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Choose the best function to use in each scenario\n\n");

	printf(COLOR_RESET   "    memcpy\t\tmemmove\n"
			             "    strcpy\t\tstrncpy\n\n");

	printf(COLOR_CYAN    "  (a) Moving all array elements backwards one position to make space for a new element at the beginning (array[0])\n");
	printf(COLOR_CYAN    "     Ans.: " COLOR_RESET "memmove\n\n");
	printf(COLOR_CYAN    "     Why?: " COLOR_RESET "str only works up til it hits an \\0; memcpy has undefined behavior with overlapping source/dest\n\n");

	printf(COLOR_CYAN    "  (b) Deleting the first char in a null-terminated string by moving all chars back one position\n");
	printf(COLOR_CYAN    "     Ans.: " COLOR_RESET "memmove\n\n");
	printf(COLOR_CYAN    "     Why?: " COLOR_RESET "str only works up til it hits an \\0; memcpy has undefined behavior with overlapping source/dest\n\n");

	printf(COLOR_CYAN    "  (c) Copying a string to a char array that may not be large enough to hold it\n);"
			             "      NOTE: if too small, truncate and add to array (without NULL terminator!)\n");
	printf(COLOR_CYAN    "     Ans.: " COLOR_RESET "strncpy\n\n");
	printf(COLOR_CYAN    "     Why?: " COLOR_RESET "memcpy would also work here, but this was my only chance to use strncpy so, may as well!\n\n");

	printf(COLOR_CYAN    "  (d) Copying one array variable into another (all contents)\n");
	printf(COLOR_CYAN    "     Ans.: " COLOR_RESET "memcpy\n\n");
	printf(COLOR_CYAN    "     Why?: " COLOR_RESET "straight up copy is easily done with memcpy. Can also use strcpy/strncpy, *if* there's only a terminator at the end\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
