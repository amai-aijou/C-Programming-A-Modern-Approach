/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-7.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Aug 21 08:09:06 PM CDT 2026
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

	int i, j, n;
	float x;
	char *input_a = "10 20 30\n";
	char *input_b = "1.0 2.0 3.0\n";
	char *input_c = "0.1 0.2 0.3\n";
	char *input_d = ".1 .2 .3\n";

	printf("-------------------EXERCISE 22-7-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Show the values of i, j, n, and x after the call, and which characters were consumed!\n\n");

	printf(COLOR_CYAN    "    n = scanf(\"%%d%%f%%d\", &i, &x, &j);\n\n");

	printf(COLOR_MAGENTA "(a) 10 20 30\n");
	n = sscanf(input_a, "%d%f%d", &i, &x, &j);
	printf(COLOR_CYAN    "    n: %d | i: %d | x: %f | j: %d\n", n, i, x, j);
	printf(COLOR_CYAN    "  Why?: " COLOR_RESET "Behaves normally. All variables filled as expected.\n\n");

	printf(COLOR_MAGENTA "(b) 1.0 2.0 3.0\n");
	n = sscanf(input_b, "%d%f%d", &i, &x, &j);
	printf(COLOR_CYAN    "    n: %d | i: %d | x: %f | j: %d\n", n, i, x, j);
	printf(COLOR_CYAN    "  Why?: " COLOR_RESET "1, .0, 2 are taken to be the operands for d f d\n\n");

	printf(COLOR_MAGENTA "(c) 0.1 0.2 0.3\n");
	n = sscanf(input_c, "%d%f%d", &i, &x, &j);
	printf(COLOR_CYAN    "    n: %d | i: %d | x: %f | j: %d\n", n, i, x, j);
	printf(COLOR_CYAN    "  Why?: " COLOR_RESET "0 .1 0 are taken to be the operands for d f d\n\n");
	
	printf(COLOR_MAGENTA "(d) .1 .2 .3\n");
	n = sscanf(input_d, "%d%f%d", &i, &x, &j);
	printf(COLOR_CYAN    "    n: %d | i: %d | x: %f | j: %d\n", n, i, x, j);
	printf(COLOR_CYAN    "  Why?: " COLOR_RESET "Scanf aborts immediately when it hits a decimal point for d. it's very strict!\n\n");


	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
