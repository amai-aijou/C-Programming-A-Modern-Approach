/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 23-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Oct  7 07:34:00 PM CDT 2026
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
long int is_hex_number(char *digit);
char digit_to_hex_char(int digit);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char *valid_hex = "A", *invalid_hex = "L23456789ABCDEFG";

	printf("-------------------EXERCISE 23-5-------------------\n\n");
	printf(COLOR_MAGENTA "Q. write a function to check if a string represents a valid hex number\n\n");

	printf(COLOR_CYAN    "  If valid, return the value as a long int\n"
			             "  If invalid, return -1\n\n");

	printf(COLOR_CYAN    "(1)   Valid Hex: %s\n", valid_hex);
	printf(COLOR_RESET   "  Value is %ld\n\n", is_hex_number(valid_hex)); 

	printf(COLOR_CYAN    "(2) Invalid Hex: %s\n", invalid_hex);
	printf(COLOR_RESET   "  Value is %ld\n\n", is_hex_number(invalid_hex)); 

	printf(COLOR_CYAN    "(3) Control Group (Known Valid Hex Function): %s\n", valid_hex);
	printf(COLOR_RESET   "  Value is %ld\n\n", is_hex_number(valid_hex)); 

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
long int is_hex_number(char *digit) {

	int i = 0;
	long int nHex;
	char *p;

	for (p = digit; p != NULL && *p != '\0'; p++) {

		if (!isxdigit(digit[i])) {

			return -1;
		}

		if ((digit[i] >= '0') && (digit[i] <= '9')) {

			nHex += (i * 16) + (digit[i] - '0');

		} else if ((digit[i] >= 'A') && (digit[i] <= 'F')) {

			nHex += (i * 16) + ((digit[i] - 'A') + 10);
		}
		i++;
	}

	return nHex;
}

// Feed this any digit and it will return the corresponding char in the string
// This works because the digit positions map to the number used (ie ""[2] is the third position, or 2)
char digit_to_hex_char(int digit) {
	return "0123456789ABCDEF" [digit];
}
