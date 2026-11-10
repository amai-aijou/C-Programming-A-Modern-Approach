/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 27-4.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Nov  9 11:54:42 AM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tgmath.h>

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

	int i;
	float f;
	double d;
	long double ld;
	float complex fc;
	double complex dc;
	long double complex ldc;

	printf("-------------------EXERCISE 27-4-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Each of these corresponds to a macro in <tgmath.h>;"
		   				 "what function from <math.h> or <complex.h> will replace it after pre-processing?\n\n");

	printf(COLOR_MAGENTA "(a) tan(i)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (tanf, tan, tanl, ctanf, ctan, ctanl, ((i)));\n\n");

	printf(COLOR_MAGENTA "(b) fabs(f)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (fabsf, fabs, fabsl, cabsf, cabs, cabsl, ((f)));\n\n");


	printf(COLOR_MAGENTA "(c) asin(d)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (asinf, asin, asinl, casinf, casin, casinl, ((d)));\n\n");


	printf(COLOR_MAGENTA "(d) exp(ld)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (expf, exp, expl, cexpf, cexp, cexpl, ((ld)));\n\n");


	printf(COLOR_MAGENTA "(e) log(fc)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (logf, log, logl, clogf, clog, clogl, ((fc)));\n\n");

	printf(COLOR_MAGENTA "(f) acosh(dc)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf(" __builtin_tgmath (acoshf, acosh, acoshl, cacoshf, cacosh, cacoshl, ((d)),((ld)));\n\n");

	printf(COLOR_MAGENTA "(g) nexttoward(d, ld)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("__builtin_tgmath (nexttowardf, nexttoward, nexttowardl, ((d)), ((ld)))\n\n");

	printf("Note: a-g are essentially using a function to choose what version of a function to use;\n"
		   " h-l do not use a function for this, so they're VERY messy. I'm sharing a truncated version of the logic instead.\n");
	printf("Note 2: __Generic is a feature from C11 that is closer to function overloading. It's like a struct that chooses the type, then takes an action\n\n");


	printf(COLOR_MAGENTA "(h) remainder(f, i)\n");
	printf(COLOR_CYAN    "  Output: \n" COLOR_RESET); 
	printf("     __Generic(f + i),\n"
		   "         float:		remainderf,\n"
		   "         double:		remainder,\n"
		   "         long double:remainderl\n"
		   "     )\n\n");


	printf(COLOR_MAGENTA "(i) copysign(d, ld)\n");
	printf(COLOR_CYAN    "  Output: \n" COLOR_RESET); 
	printf("     __Generic((d + ld),\n");
	printf("        float:       copysignf,\n");
	printf("        double:      copysign,\n");
	printf("        long double: copysignl\n");
	printf("     )\n\n");

	printf(COLOR_MAGENTA "(j) carg(i)\n");
	printf(COLOR_CYAN    "  Output: \n" COLOR_RESET); 
	printf("     __Generic((i + i),\n");
	printf("         float:       cargf,\n");
	printf("         double:      carg,\n");
	printf("         long double: cargl,\n");
	printf("         default:     carg\n");
	printf("     )\n\n");

	printf(COLOR_MAGENTA "(k) cimag(f)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("     __Generic((f + f),\n");
	printf("         float:       cimagf,\n");
	printf("         double:      cimag,\n");
	printf("         long double: cimag1,\n");
	printf("     )\n\n");

	printf(COLOR_MAGENTA "(l) conj(ldc)\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf("     __Generic((ldc + ldc),\n");
	printf("         float _Complex:       conjf,\n");
	printf("         double _Complex::     conj,\n");
	printf("         long double _Complex: conj1,\n");
	printf("     )\n\n");

	// TEST AREA FOR PREPROCESSOR
	tan(i);

	fabs(f);

	asin(d);

	exp(ld);

	log(fc);

	acosh(dc);

	nexttoward(d, ld);

	remainder(f, i);

	copysign(d, ld);

	carg(i);

	cimag(f);

	conj(ldc);

	// END TEST AREA FOR PREPROCESSOR
	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
