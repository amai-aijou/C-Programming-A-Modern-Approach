/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-9.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue Jul 28 11:06:15 AM CDT 2026
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
int count_ones(unsigned char ch);
int count_ones_loopless(unsigned char ch);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	unsigned char nChar;

	printf("-------------------EXERCISE 20-9-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Write this function, both with and without using a loop! \n\n");
	
	printf(COLOR_CYAN "Enter a number, please: " COLOR_RESET);
	scanf("%d", &nChar);
	printf("\n");

	printf(COLOR_MAGENTA "(a) int count_ones(unsigned char ch);\n");
	printf(COLOR_CYAN    "    output :" COLOR_RESET "There are %d ones in %d (ASCII: %d)\n\n", count_ones(nChar), nChar, nChar);

	printf(COLOR_MAGENTA "(b) int count_ones_loopless(unsigned char ch);\n");
	printf(COLOR_CYAN    "    output :" COLOR_RESET "There are %d ones in %d (ASCII: %d)\n\n", count_ones_loopless(nChar), nChar, nChar);

	printf(COLOR_RESET   "    sizeof unsigned char: %d\n\n", (sizeof(unsigned char) * 8));
	printf(              "    The loopless function depends on turning the eight 1-bit numbers...into four 2-bit...\n"
			             "    into two 4-bit...and finally, into one eight-bit number, which is the same size as the 8-bit char 'container' it sits in.\n"
						 "    As it is a single number, it can be read as a single decimal via %%d\n\n");

	printf(              "    You can double the 'size' of a number by making a mask twice its size (for 2-bit, this was 01010101...for 4-bit, 00110011).\n"
			             "    You then apply that mask to the number...then, to that number shifted by the bitrate of the number (1, 2, 4, for 2/4/8-bit).\n"
						 "    Finally, you add those two together through binary addition, and use it as the input for the next\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int count_ones(unsigned char ch) {

	int i, ones = 0, digit;


	for (i = 0; i < (sizeof(unsigned char) * 8); i++) {
		if ((digit = ch >> (i + 1 - 1)) & ~(~0 << 1)) {
			ones++;
		}
	}

	return ones;
}

int count_ones_loopless(unsigned char ch) {

	unsigned char twoBit, fourBit, eightBit;

	twoBit = (ch & 0x55) + ((ch >> 1) & 0x55);
	fourBit = (twoBit & 0x33) + ((twoBit >> 2) & 0x33);
	eightBit = (fourBit & 0xF) + ((fourBit >> 4) & 0xF);

	return eightBit;
}

/*
1-bit:
	10 11 01 10

2-bit mask:
	01 01 10 11 ( ch >> 1)
   &01 01 01 01 (0x55)
    -----------
	01 01 00 01

	10 11 01 10 (ch)
   +01 01 01 01
    -----------
	00 01 01 00

	01 01 00 01
   +00 01 01 00
    -----------
	01 10 01 01 (2-bit number)

4-bit mask:
	00 01 10 01 (1-bit >> 2)
   &00 11 00 11 (0x33)
    -----------
	00 01 00 01

	01 10 01 01 (1-bit)
   &00 11 00 11 (0x33)
    -----------
	00 10 00 01

	00 01 00 01
	00 10 00 01
    -----------
	00 11 00 10 (4-bit number)

8-bit mask:
	00 00 00 11 (2-bit >> 4) 
   &00 00 11 11 (0xF)
    -----------
	00 00 00 11

	00 11 00 10
   &00 00 11 11 (0xF)
    -----------
	00 00 00 10

	00 00 00 11
	00 00 00 10
    -----------
	00 00 01 01 (8-bit number)

The "unsigned char" is only eight bits; since the bit-rate now matches the size of the container,
  this can be read as a normal human number! (in this example, "5")
*/
