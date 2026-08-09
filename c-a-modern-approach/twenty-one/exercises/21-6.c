/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 21-6.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Aug  9 03:33:21 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <ctype.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

#define UPPER 0x01

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 21-6-------------------\n\n");
	printf(COLOR_MAGENTA "Q. For the macros defined in <ctype.h>:\n\n");

	printf(COLOR_CYAN    "  #define _UPPER 0x01\n"
			             "  #define _LOWER 0x02\n"
			             "  #define _DIGIT 0x04\n"
			             "  #define _CONTROL 0x08\n"
			             "  #define _PUNCT 0x10\n"
			             "  #define _SPACE 0x20\n"
			             "  #define _HEX 0x40\n"
			             "  #define _BLANK 0x80\n\n");

	printf(COLOR_MAGENTA "(a) Why do the 'bit' macros above have an underscore?\n");
	printf(COLOR_CYAN    "  Guess: " COLOR_RESET "Because _ + Uppercase is globally reserved in C99, to stop other things from using it\n"
		                 "         (but also, presumably, to be kind and let you use UPPER for your own purposes)\n\n");

	printf(COLOR_MAGENTA "(b) Explain what _ctype[] contains\n"
		   COLOR_RESET   "      _ctype[] is actually a lookup table, meaning it's an array whose decimal values break down into binary flags (for the above #define statements!)\n"
		                 "      This means the first (least significant) bit is, 'is this an uppercase?'. It's meant to describe each digit, for use with islower(), isupper(), etc\n\n");

	printf(COLOR_CYAN    "    #9   horizontal tab: " COLOR_RESET "10101000\n"
		   COLOR_CYAN    "    #32 space character: " COLOR_RESET "10100000\n"
		   COLOR_CYAN    "    #65  the letter 'A': " COLOR_RESET "01000101\t\tNote: This is hex because hex = 0-9, A-F. Clever, huh?\n"
		   COLOR_CYAN    "    #94 the ^ character: " COLOR_RESET "00010000\n\n");

	printf(COLOR_MAGENTA "(b) What's the advantage to doing it this way, in an array?\n"
		   COLOR_RESET   "     A lookup table is much faster than pulling and running a function, and since it's done as bits in a lookup table, it uses exponentially less data, too!\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
