/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 21-4.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Aug  9 11:55:50 AM CDT 2026
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

	printf("-------------------EXERCISE 21-4-------------------\n\n");
	printf(COLOR_MAGENTA "Q. What are all reserved identifiers in the Future Library Directions section of the C99 standard?\n\n");

	printf(COLOR_CYAN    "Reserved when a specific header is in use:\n");
	printf(COLOR_RESET	 "E + digit or upper-case\n"
			 			 "FE + uppercase\n"
						 "DBL_, DEC32_, DEC64_, DEC128_, DEC_, FLT_, LDBL_ + uppercase\n"
						 "PRI SCN + lowercase or X\n"
						 "LC_ + uppercase\n"
						 "FP_ MATH_ + uppercase\n"
						 "SIG or SIG_ + uppercase\n"
						 "ATOMIC_ + uppercase, typedef atomic_ or memory_ + lowercase, memory_order_ + lowercase \n"
						 "typedef int or uint ending with _t, Macro INT or UINT ending with _MAX, _MIN, _WIDTH, _C\n"
						 "TIME_ + uppercase\n"
						 "macros using cnd_, mtx_, thrd_ tss_ + lowercase\n"
						 "types beginning with ckd_\n"


	printf("\n----------------------------\n");

	printf(COLOR_CYAN    "Reserved at all times, regardless of whether its header is included:\n");
	printf(COLOR_RESET   "cacospi  casinpi  catanpi  ccompoundn  ccospi  cerfc  cerf  cexp10m1  cexp10  cexp2m1  cexp2  cexpm1  clgamma\n"
			             "clog10p1  clog10  clog1p  clog2p1  clog2  clogp1  cpown  cpowr  crootn  crsqrt  csinpi  ctanpi  ctgammacacospi\n"
						 "casinpi  catanpi  ccompoundn  ccospi  cerfc  cerf  cexp10m1  cexp10  cexp2m1  cexp2  cexpm1  clgamma  clog10p1\n"
						 "clog10  clog1p  clog2p1  clog2  clogp1  cpown  cpowr  crootn  crsqrt  csinpi  ctanpi  ctgamma\n"
						 "...or any of these names suffixed with f or l\n"
	                     "is*  to*, followed by a lower-case letter\n"
						 "str wcs + lowercase letter\n"
						 "is + lowercase\n"
						 "cr_\n"
						 "atomic_ + lowercase\n"
						 "str or WCS + lowercase\n"
						 "str, mem, wcs + lowercase\n"
						 "functions using cnd_, mtx_, thrd_ tss_ + lowercase\n"
						 "wcs + lowercase\n"
						 "is* to* + lowercase\n"
						 "functions beginning with ckd_\n"

	printf(COLOR_RESET   "\n");

	return 0;
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
