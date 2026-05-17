/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-17.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 17 01:03:07 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>


/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int example_function(int i);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	enum {FALSE, TRUE} b;
	int i;

	printf("-----------------------------------EXERCISE 16-3-----------------------------------\n");
	// (a)
	b = FALSE;
	printf("(a) b = FALSE;\n");
	printf("    LEGAL.   SAFE.\n");
	printf("    An unnamed enum has been declared alongside b, and b is now initialized.\n\n");
	printf("    ex. - value of b: %d\n\n", b);

	// (b)
	b = i;
	printf("(b) b = i\n");
	printf("    LEGAL. UNSAFE.\n");
	printf("    i is an integer, so it's legal to assign its value to b; however, i is not guaranteed\n");
	printf("    to fall within the range of b, meaning you could be assigning 20 to a boolean (1/0) enum!\n");
	printf("    ex. - value of i: %d\n", i);
	printf("    ex. - value of b: %d\n\n", b);

	// (c)
	b++;
	printf("(c) b++\n");
	printf("    LEGAL. UNSAFE.\n");
	printf("    This is a legal operation; however, as only FALSE (0) and TRUE (1) are declared,\n");
	printf("    if b = TRUE (1), or b++ called multiple times, it'll create a legal integer outside the enum range!)\n");
	printf("    ex. - value of b: %d\n", b);
	b++;
	printf("    ex. - value of b: %d\n\n", b);

	// (d)
	i = b;
	printf("(d) i = b\n");
	printf("    LEGAL.   SAFE.\n");
	printf("    b is an integer. Assigning b to i, an already-declared integer, is legal, and\n");
	printf("    since i has fewer (human-imposed) limitations than b, is safe..\n");
	printf("    ex. - value of i: %d\n\n", i);

	// (e)
	i = 2 * b + 1;
	printf("(e) i = 2 * b + 1;\n");
	printf("    LEGAL.   SAFE.\n");
	printf("    There is no legal number b can be that is not legal; however, the statement doesn't make a ton of sense.\n");
	printf("    By 'safe', they mean 'yields a meaningful result', and this will always yield 1 or 3 if b is used properly.\n");
	printf("    ex. - value of i: %d\n\n", i);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
