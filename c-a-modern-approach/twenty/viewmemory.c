/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: viewmemory.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Jul 20 09:05:46 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	unsigned int addr;
	int i, n;
	BYTE *ptr;

	printf("Address of main function: %x\n", (unsigned int) main);
	printf("Address of addr variable: %x\n", (unsigned int) &addr);

	printf("\nEnter a (hex) address: ");
	scanf("%x", &addr);
	printf("Enter a number of bytes to view: ");
	scanf("%d", &n);

	printf("\n");
	printf("Address				Bytes				Characters\n");
	printf("-------	 -----------------------------	----------\n");

	ptr = (BYTE *) addr;

	for (; n > 0; n -= 10) {

		printf("%8x  ", (unsigned int) ptr);

		for (i = 0; i < 10 && i < n; i++) {

			printf("%.2X ", *(ptr + i));
		}
		for (; i < 10; i++) {

			printf("    ");
		}
		printf("   ");
		for (i = 0; i < 10 && i < n; i++) {

			BYTE ch = *(ptr + i);

			if (!isprint(ch)) {
				ch = '.';
			}

			printf("%c", ch);
		}
		printf("\n");
		ptr += 10;
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

