/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 15-4.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May  3 08:01:55 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#define DEBUG
#include "15-4.h"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int i = 1, j = 2, k = 3;

#ifdef DEBUG
	printf("Output if DEBUG is defined:\n");
#else
	printf("Output if DEBUG is not defined:\n");
#endif

	PRINT_DEBUG(i);
	PRINT_DEBUG(j);
	PRINT_DEBUG(k);
	PRINT_DEBUG(i + j);
	PRINT_DEBUG(2 * i + j - k);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                     ❤︎︎࣪    A N S W E R S    ❤︎︎࣪   
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
(a) Standard program output
  Output if DEBUG is defined:
  Value of i: 1
  Value of j: 2
  Value of k: 3
  Value of i + j: 3
  Value of 2 * i + j - k: 1

(b) Program output with DEBUG removed (gcc -U DEBUG)
  Output if DEBUG is not defined:

(c) Explain why the output is different in (a) and (b)
  First, #ifdef DEBUG prints a different statement in 15-4.c when debug is off.
  Second, in 15-4.h, PRINT_DEBUG(n) is defined as blank, so pre-processing removes it

(d) Is it necessary for DEBUG to be defined *before* debug.h is included?
  Yes, it is necessary. If you define it after debug.h is included, it will also have 
  been defined after debug.h was pre-processed. This means that you lose the definition
  of PRINT_DEBUG, while (erroneously) retaining the "output if debug is defined" statement


*****************************************************************/
