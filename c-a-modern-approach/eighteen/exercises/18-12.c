/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 18-12.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Jun 28 11:28:32 AM CDT 2026
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
float dummy_function(long l);
int return_dummy_function(double x);
int (*f(float (*)(long), char *))(double);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-12-------------------\n\n");
	printf(COLOR_MAGENTA "Given the following function declaration:\n"
		   COLOR_CYAN    "    int (*f(float (*)(long), char *))(double);\n\n");

	printf(COLOR_MAGENTA "  (a) Provide a description:\n");
	printf(COLOR_CYAN    "    f is: "
		   COLOR_RESET	 "a function with two parameters:\n\n"
		                 "            1. a function pointer with a long parameter that returns a float\n"
				  	     "            2. a char pointer\n\n"
						 "          f returns a function pointer that takes a double parameter and returns an int\n\n");

	printf(COLOR_MAGENTA "  (b)Call f() in a program:\n"
		   COLOR_CYAN    "    helper functions:\n"
		   COLOR_RESET	 "      float dummy_function(long l);\n"
	                     "      int return_dummy_function(double x);\n\n"
		   COLOR_CYAN    "    call f and store the result, int (*)(double), in a pointer::\n"
	       COLOR_RESET   "      int (*result_ptr)(double) = f(dummy_function, \"dummy string\");\n\n"
		   COLOR_CYAN    "    call the int (*)(double) pointer, and store the integer it creates:\n"
	       COLOR_RESET   "      int result = result_ptr(6.99);\n\n"
		   COLOR_CYAN    "    show the resulting integer as proof the conversion occurred:\n"
	       COLOR_RESET   "      printf(\"Result should be an integer: %%d\\n\", result);\n\n");

	printf(COLOR_MAGENTA "  Running the function for proof:\n" COLOR_RESET);

	// call f, and store the result, int (*)(double)
	int (*result_ptr)(double) = f(dummy_function, "dummy string");

	// call the int (*)(double) result, and store the resulting int
	int result = result_ptr(6.99);

	// show the resulting integer!
	printf("      Result should be an integer: %d\n\n", result);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// dummy function to use as a parameter of f
float dummy_function(long l) {

	printf("      Dummy_function parameter called (changes long to float)\n");
	return (float) l;
}

// dummy function to use for the return type of f
int return_dummy_function(double x) {

	printf("      Return function called (changes double to int)\n");

	// returns the same double variable, but cast to an int
	return (int)x;
}

int (*f(float (*fp)(long), char *string))(double) {

	printf("      Function f called\n");

	return return_dummy_function;
}


