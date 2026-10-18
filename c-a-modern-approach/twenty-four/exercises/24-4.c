/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 24-4.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Oct 17 08:18:02 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

#define TRY_MATH_FCN(x,y) (try_math_fcn(x,y, ("Error in call of " #x)))

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
double try_math_fcn(double (*sqrt)(double), double input, char *str);
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	double y;
	double x = 25;

	printf("-------------------EXERCISE 24-4-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Wrapping functions and testing return values \n\n");

	printf(COLOR_CYAN    "    double sqrt(double x);\n\n");

	printf(COLOR_MAGENTA "(a) Wrap sqrt in an error-handling test function\n\n");
	printf(COLOR_CYAN    "    double try_math_fcn(double (*fcn)(double), double input, char *str)\n\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	y = try_math_fcn(sqrt, x, "Error in call of");
	printf("%.1lf\n\n", y);

	printf(COLOR_MAGENTA "(b) Same as above, but build the error message from the function's name\n\n");
	printf(COLOR_CYAN    "    #define TRY_MATH_FCN(x,y,z) (try_math_fcn(x,y, (z ## x)))\n\n");
	x = -9;
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	y = TRY_MATH_FCN(sqrt,x);
	printf("%.1lf\n\n", y);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
double try_math_fcn(double (*fcn)(double), double input, char *str) {

	double y;

	errno = 0;
	y = fcn(input);
	if (errno != 0) {
		perror(str);
		exit(EXIT_FAILURE);
	}

	return y;
}
