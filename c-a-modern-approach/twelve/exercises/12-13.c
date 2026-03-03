/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 12-13.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Mar  2 05:48:09 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define N 10

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void initialize_array(double ident[][N]);
void initialize_array_old(double ident[][N]);
void zero_array(double ident[][N]);
void print_array(double ident[][N]);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	double ident[N][N];

	initialize_array_old(ident);
	print_array(ident);
	printf("\n\n");

	zero_array(ident);
	print_array(ident);
	printf("\n\n");

	initialize_array(ident);
	print_array(ident);
	printf("\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void initialize_array(double ident[][N]) {

	double *p;
	int a = 0;

	for (p = *ident; p < *ident + (N * N); p++) {

		if (a % 11 == 0) {
			*p = 1.0;		
		} else {
			*p = 0.0;
		}
		a++;
	}
}

void initialize_array_old(double ident[][N]) {
	
	int row, col;

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (row == col) {
				ident[row][col] = 1.0;
			} else {
				ident[row][col] = 0.0;
			}
		}
	}

}

void zero_array(double ident[][N]) {

	int row, col;

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			ident[row][col] = 0.0;
		}
	}

}

void print_array(double ident[][N]) {

	int row, col;

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			printf("%.2lf ", ident[row][col]);
		}
		printf("\n");
	}
}
