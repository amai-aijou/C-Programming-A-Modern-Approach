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
#define COLOR_BLUE "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"


/*
(COLOR_CYAN "(c) float *(*x(void))(int);\n");


// (d) void (*x(int, void (*y)(int)))(int);



// then plug in: void (*x(int, Ptr_y))(int);
typedef void Fcn_ptr_void_x(int);
typedef Fcn_ptr_void_x *Fcn_ptr_x;
typedef Fcn_ptr_x Fcn_x(int, Ptr_y);
Fcn_x x;

*/
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-8-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Fully describe the type of x in each declaration:\n\n");

	printf(COLOR_CYAN "(a) char (*x[10])(int);\n");
	printf(COLOR_MAGENTA "  x is: \n" COLOR_RESET "    an array of ten function pointers that have an int argument and return a char\n");
	printf(COLOR_MAGENTA "  typedef:\n" COLOR_RESET
	"      typedef char Fcn(int);\n"
	"      typedef Fcn *Fcn_ptr;\n"
	"      typedef Fcn_ptr Fcn_ptr_array[10];\n"
	"      Fcn_ptr_array x;\n\n");

	printf(COLOR_CYAN "(b) int (*x(int))[5];\n");
	printf(COLOR_MAGENTA "  x is: \n" COLOR_RESET "    a function with an int argument and returns an pointer to an array of five ints\n");
	printf(COLOR_MAGENTA "  typedef:\n" COLOR_RESET
	"      typedef int Fcn_ptr_array[5];\n"
	"      typedef Fcn_ptr_array *Fcn_ptr;\n"
	"      typedef Fcn_ptr Fcn_int(int);\n"
	"      Fcn_int x;\n\n");

	printf(COLOR_CYAN "(c) float *(*x(void))(int);\n");
	printf(COLOR_MAGENTA "  x is: \n" COLOR_RESET "    a function with a void parameter that returns a pointer to a function with an int parameter and a float return type \n");
	printf(COLOR_MAGENTA "  typedef:\n" COLOR_RESET
	"      typedef float Fcn_ptr_float(int);\n"
	"      typedef Fcn_ptr_float *Fcn_ptr;\n"
	"      typedef Fcn_ptr Fcn_void(void);\n"
	"      Fcn_void x;\n\n");

	printf(COLOR_CYAN "(d) void (*x(int, void (*y)(int)))(int);\n");
	printf(COLOR_MAGENTA "x is: \n" COLOR_RESET "    a function with an int parameter and a void parameter y (a function pointer that takes an int),\n"
		                 "    which returns a void function pointer that takes an int\n");
	printf(COLOR_MAGENTA "  typedef:\n" COLOR_BLUE
	"      // build y first\n" COLOR_RESET
	"      typedef void Fcn_ptr_y(int);\n"
	"      typedef Fcn_ptr_y *Ptr_y;\n"
	"      Ptr_y y;\n\n");

	return 0;
}
