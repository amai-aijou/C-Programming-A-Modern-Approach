/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name:  
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Feb 25 11:27:07 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

#define N 10

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = &a[0], *q = &a[N-1], temp;
	int x;

	printf("This feels a bit messy at first, but it makes sense once you extract it this way\n\n");
	while (p < q) {

		// The value of *p is assigned to temp
		temp = *p;
		
		printf("temp = *p\n");
		printf("     p: %d | q: %d\n", p, q);
		printf("    *p: %d | *q: %d | temp: %d\n", *p, *q, temp);
		printf("Array a: ");
		for (x = 0; x < N; x++) {
			printf("%d ", a[x]);
		}
		printf("\n");

		// The value of *q is assigned to *p; the memory address of p is incremented
		// NOTE: p++ increments the address by four, not one (as p is an integer, taking up four bytes in this compiler)!
		*p++ = *q;

		printf("*p++ = *q\n");
		printf("     p: %d | q: %d\n", p, q);
		printf("    *p: %d | *q: %d | temp: %d\n", *p, *q, temp);
		printf("Array a: ");
		for (x = 0; x < N; x++) {
			printf("%d ", a[x]);
		}
		printf("\n");

		// The value of temp is assigned to *q, and the memory address of q decremented
		*q-- = temp;

		printf("*q-- = temp\n");
		printf("     p: %d | q: %d\n", p, q);
		printf("    *p: %d | *q: %d | temp: %d\n\n", *p, *q, temp);
		printf("Array a: ");
		for (x = 0; x < N; x++) {
			printf("%d ", a[x]);
		}
		printf("\n");
	}

	printf("Q: What will by the contents of the a array after the following statements are executed?\n");
	printf("A: The array is reversed.\n");
	printf("  1. The value of *p is assigned to temp.\n");
	printf("  2. The value of *q is assigned to *p, and the memory address of p incremented (note: this increased by four, to the next integer!)\n");
	printf("  3. The value of temp is assigned to *q, and the memory address of q decremented\n\n");
	return 0;
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                       ❤︎︎࣪    N O T E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
/*
 * *p = &a[0]
 *  *q = &a[9]
 *
 * temp = 1
 * p 11
 * 9 = temp
 *
 * temp = 
 */

