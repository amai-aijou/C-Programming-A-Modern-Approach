/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Tue May 12 03:59:07 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	// (a)
	struct c {
		double real;
		double imaginary;
	} c1 = {0.0, 1.0}, // (b)
	  c2 = {1.0, 0.0},
	  c3;

	printf("Before (c) operations:\n");
	printf("c1.real: %.1f\n", c1.real);
	printf("c1.imaginary: %.1f\n", c1.imaginary);
	printf("c2.real: %.1f\n", c2.real);
	printf("c2.imaginary: %.1f\n\n", c2.imaginary);

	// (c)
	c1 = c2;

	printf("After (c) operations:\n");
	printf("c1.real: %.1f\n", c1.real);
	printf("c1.imaginary: %.1f\n", c1.imaginary);
	printf("c2.real: %.1f\n", c2.real);
	printf("c2.imaginary: %.1f\n\n", c2.imaginary);

	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;

	printf("After (d) operations:\n");
	printf("c3.real: %.1f\n", c3.real);
	printf("c3.imaginary: %.1f\n", c3.imaginary);
	return 0;
}
