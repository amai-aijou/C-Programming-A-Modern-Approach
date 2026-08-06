/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-14.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Aug  3 03:19:43 PM CDT 2026
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

struct float_struct {
	unsigned int frac:23;
	unsigned int exp:  8;
	unsigned int sign: 1;
};

union float_convert {
	unsigned int i;
	float f;
	struct float_struct bitfield;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 20-14-------------------\n\n");
	printf(COLOR_MAGENTA "A float is typically 32-bit, and comprised of:\n\n"
		   COLOR_CYAN    "   * 1-bit sign\n"
						 "   * 8-bit exponent\n"
						 "   * 23-bit fraction\n\n"
		   COLOR_MAGENTA "Create an unsigned int struct that emulates this (use the bit-field order for your compiler!)\n\n");

	printf(COLOR_MAGENTA "Note: GCC uses the IEEE 754 standard, which defines a float backwards:\n\n"
		   COLOR_CYAN	 "   * 23-bit fraction\n"
						 "   * 8-bit exponent\n"
		   			     "   * 1-bit sign\n\n");

	union float_convert var1;

	var1.f = -2.0;
	
	printf(COLOR_CYAN    " size of   float: " COLOR_RESET "%d\n", sizeof(float) * 8);


	printf(COLOR_MAGENTA "A union can be used to access the data in various ways:\n");
	printf(COLOR_CYAN    " uint  : " COLOR_RESET "%u\n", var1.i);
	printf(COLOR_CYAN    " Float : " COLOR_RESET "%f\n", var1.f);
	printf(COLOR_CYAN    " Struct: " COLOR_RESET "%u / %u / %u\n\n", var1.bitfield.sign, var1.bitfield.exp, var1.bitfield.frac);

	union float_convert var2;
	var2.bitfield.frac = 0;
	var2.bitfield.exp = 128;
	var2.bitfield.sign = 1;


	printf(COLOR_MAGENTA "We can take the values from the above, and input it as bits, then receive a full float out after:\n");
	printf(COLOR_CYAN    " uint  : " COLOR_RESET "%u\n", var2.i);
	printf(COLOR_CYAN    " Float : " COLOR_RESET "%f\n", var2.f);
	printf(COLOR_CYAN    " Struct: " COLOR_RESET "%u / %u / %u\n\n", var2.bitfield.sign, var2.bitfield.exp, var2.bitfield.frac);


	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
