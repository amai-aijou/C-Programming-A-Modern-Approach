/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 12-12.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Mar  1 06:47:22 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void find_two_largest(const int *a, int n, int *largest, int *second_largest);
void find_two_largest_subscript(const int a[], int n, int *largest, int *second_largest);
void find_two_largest_optimized(const int *a, int n, int *largest, int *second_largest);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n = 5;
	const int a[5] = {2, 4, 6, 8, 10};
	int largest, second_largest;

	largest = 0;
	second_largest = 0;
	find_two_largest(a, n, &largest, &second_largest);
	printf("find_two_largest(): %d, %d\n", largest, second_largest);

	largest = 0;
	second_largest = 0;
	find_two_largest_subscript(a, n, &largest, &second_largest);
	printf("find_two_largest_subscript(): %d, %d\n", largest, second_largest);

	largest = 0;
	second_largest = 0;
	find_two_largest_optimized(a, n, &largest, &second_largest);
	printf("find_two_largest_optimized(): %d, %d\n", largest, second_largest);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {

	const int *p;

	for (p = a; p < a + n; p++) {
		if (*p > *largest) {
			*largest = *p;
		}	

	}

	for (p = a; p < a + n; p++) {
		if ((*p > *second_largest) && *p < *largest) {
			*second_largest = *p;
		}
	}
}

void find_two_largest_subscript(const int *a, int n, int *largest, int *second_largest) {

	int i;

	for (i = 0; i < n; i++) {
		if (a[i] > *largest) {
			*largest = a[i];
		}
	}

	for (i = 0; i < n; i++) {
		if (a[i] > *second_largest && a[i] < *largest) {
			*second_largest = a[i];
		}
	}

}

void find_two_largest_optimized(const int *a, int n, int *largest, int *second_largest) {

	const int *p;

	for (p = a; p < a + n; p++) {
		if (*p > *largest) {
			*second_largest = *largest;
			*largest = *p;
		}	
	}
}
