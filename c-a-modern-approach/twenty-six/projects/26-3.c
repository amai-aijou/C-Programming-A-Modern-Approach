/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-3.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Nov  4 06:29:38 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int *create_array(int n);
void print_array(int n, int *arr);
int compare_ints(const void *p, const void *q);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n1 = 100, n2 = 10000, n3 = 100000;
	int *p1, *p2, *p3;
	clock_t start_clock = clock();

	//Array 1 --------------
	p1 = create_array(n1);
	start_clock = clock();
	qsort(p1, n1, sizeof(int), compare_ints);
	printf("Array 1 - %d positions.\nProcessor time used: %g sec.\n\n",
			n1, (clock() - start_clock) / (double) CLOCKS_PER_SEC);

	//Array 2 --------------
	p2 = create_array(n2);
	start_clock = clock();
	qsort(p2, n2, sizeof(int), compare_ints);
	printf("Array 2 - %d positions.\nProcessor time used: %g sec.\n\n",
			n2, (clock() - start_clock) / (double) CLOCKS_PER_SEC);

	//Array 3 --------------
	p3 = create_array(n3);
	start_clock = clock();
	qsort(p3, n3, sizeof(int), compare_ints);
	printf("Array 3 - %d positions.\nProcessor time used: %g sec.\n\n",
			n3, (clock() - start_clock) / (double) CLOCKS_PER_SEC);

	// Cleanup
	free(p1);
	free(p2);
	free(p3);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int compare_ints(const void *p, const void *q) {

	const int *p1 = p;
	const int *q1 = q;

	if (*p1 < *q1) {
		return -1;
	} else if (*p1 == *q1) {
		return 0;
	} else
		return 1;
}



int *create_array(int n) {

	int i = 0, j = 0;
	int *p;

	if ((p = malloc(sizeof(int) * n)) == NULL) {
		printf("Error: Could not allocate array; requires %d bits of memory!\n", n);
		exit(EXIT_FAILURE);
	}

	for (i = 0, j = (n-1); i < n; i++, j--) {
		p[i] = j;
	}

	return p;
}

void print_array(int n, int *arr) {

	int i;

	for (i = 0; i < n; i++) {
		printf("%6d", arr[i]);

		if ((i +1) < n) {
			printf(" ");
		}

		if ((i % 10) == 9) {
			printf("\n");
		}
	}
	printf("\n");
}

/*
	printf("DEBUG - survived the creation!\n");
*/
