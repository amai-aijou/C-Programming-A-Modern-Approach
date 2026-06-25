/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 18-8.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tues Jun 23 06:14:55 PM CDT 2026
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

// (a) char (*x[10])(int);
typedef char Fcn_a(int);
typedef Fcn_a *Fcn_ptr_a;
typedef Fcn_ptr_a Fcn_ptr_array_a[10];
typedef Fcn_ptr_array_a v;

// (b) int (*x(int))[5];
typedef int Fcn_ptr_b[5];
typedef Fcn_ptr_b *Fcn_int_b;
typedef Fcn_int_b Fcn_b(int);
typedef Fcn_b x;

// (c) float *(*x(void))(int);
typedef float *Fcn_ptr_c(int);
typedef Fcn_ptr_c *Fcn_void_c;
typedef Fcn_void_c Fcn_c(void);
typedef Fcn_c x;

// (d) void (*x(int, void (*y)(int)))(int);\n");

// build y first
typedef  Fcn_y;
typedef Fcn_y y;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-8-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Fully describe the type of x in each declaration:\n\n");

	printf(COLOR_CYAN "(a) char (*x[10])(int);\n");
	printf(COLOR_MAGENTA "x is: " COLOR_RESET "an array of ten function pointers that have an int argument and return a char\n\n");

	printf(COLOR_CYAN "(b) int (*x(int))[5];\n");
	printf(COLOR_MAGENTA "x is: " COLOR_RESET "a function with an int argument and returns an pointer to an array of five ints\n\n");

	printf(COLOR_CYAN "(c) float *(*x(void))(int);\n");
	printf(COLOR_MAGENTA "x is: " COLOR_RESET "a function with a void parameter that returns a pointer to a function with an int parameter and a float return type \n\n");

	printf(COLOR_CYAN "(d) void (*x(int, void (*y)(int)))(int);\n");
	printf(COLOR_MAGENTA "x is: " COLOR_RESET "a function with an int parameter and a void parameter y (a function pointer that takes an int),\n"
		                 "which returns a void function pointer that takes an int\n\n");

	return 0;
}
