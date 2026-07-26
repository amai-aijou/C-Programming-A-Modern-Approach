/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-7
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Jul 26 10:45:05 AM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	unsigned int i = 8, nInput, rotated;
	int n = 0;
	char direction;

	srand((unsigned) time(NULL));

	printf("-------------------EXERCISE 20-7-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Write these functions: \n\n");

	printf(COLOR_CYAN    "unsigned int rotate_left(unsigned int i, int n);\n");
	printf(COLOR_CYAN    "unsigned int rotate_right(unsigned int i, int n);\n\n");


	printf("---------------------------------------------------\n\n");
	printf("Variable size: %d\n\n", (sizeof(i) * 8));
	printf(COLOR_CYAN    "Enter an unsigned number: " COLOR_RESET);
	scanf(" %u", &nInput);

	printf(COLOR_CYAN    "Number of bits to rotate: " COLOR_RESET);
	scanf(" %d", &n);

	printf(COLOR_CYAN    "Rotate right [r] or left [l] (default is random!): " COLOR_RESET);
	scanf(" %c", &direction);

	printf("direction: %c", direction);
	switch (direction) {
		case 'r': rotated = rotate_right(nInput, n);
				  break;
		case 'l': rotated = rotate_left(nInput, n);
				  break;
		default:
			if (rand() % 2) {
				rotated = rotate_left(nInput, n);
			} else {
				rotated = rotate_right(nInput, n);
			}
	}

	printf(COLOR_CYAN    "\nRotated value: " COLOR_RESET "%u\n\n", rotated);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
unsigned int rotate_left(unsigned int i, int n) {

	// If no rotation occurs, return i. This prevents errors from trying to rotate more bits than exist in the variable!
	if (n == 0) {
		return i;
	}

	return (i << n) | (i >> ((sizeof(i) * 8) - n)) ;
}

unsigned int rotate_right(unsigned int i, int n) {

	// If no rotation occurs, return i. This prevents errors from trying to rotate more bits than exist in the variable!
	if (n == 0) {
		return i;
	}

	return (i >> n) | (i << ((sizeof(i) * 8) - n)) ;
}
