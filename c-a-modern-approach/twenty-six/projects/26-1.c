/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Nov  4 05:30:46 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RUNS 1000

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int i = 0, m = 0, n = 0;
	int count = 1;
	int lines = 0;
	int zeroes = 0, ones = 0;

	srand(time(NULL));

	for (i = 0; i < MAX_RUNS ; i++) {
		n = m;

		// (a):
		//m = (rand() % 2);
		
		// (b):
		m = ((rand() >> 15) % 2);

		if (m == 0) {
			zeroes++;
		} else {
			ones++;
		}

		if ( i % 50 == 0) {
			printf("\n # | rng | * | lines\n");
			printf("--------------------\n");
		}

		if (m == n) {
			count++;
			if ( i + 1 == MAX_RUNS) {
				printf("%d: %d | %d (%d)\n", (i + 1), n, count, lines);
			}
		} else {
				printf("%d: %d | %d (%d)\n", (i + 1), n, count, lines);
				count = 1;
				lines++;
		}
	}

	printf("--------------------\n");
	printf("      COMPLETE!     \n\n");
	printf("zeroes: %d | Ones: %d\n\n", zeroes, ones);
	printf("Note: Modern glibc is really, really good. The book is talking about 20+ years ago, when rng sucked.\n");
	printf("      But pretending this was still an issue, you can capture the most significant bits of rand(), instead of the least :)\n\n");


	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

