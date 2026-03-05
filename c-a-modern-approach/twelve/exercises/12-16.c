/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 12-16.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Mar  2 08:13:19 PM CST 2026
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
bool search(int a[*][24], int n, int key);
void initialize_array(int temperatures[*][24]);
void print_row(int i, int temperatures[*][24]);
void print_array(int temperatures[*][24]);
int *find_largest(int a[], int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n = 7 * 24;
	int temperatures[7][24];
	int key = 0;
	int i, x, y = 0;

	initialize_array(temperatures);

	printf("Please enter a key (search 7 to test code): ");
	scanf("%d", &key);

	if (search(temperatures, n, key) == true) {
		printf("Term %d was found\n", key);
	} else {
		printf("not found\n");
	}

	printf("Choose a row to print: ");
	scanf("%d", &i);

	print_row(i, temperatures);

	print_array(temperatures);


	//12-16.c: Print the highest temp in the array for each day of the week (each row)
	for (x = 0; x < 7; x++) {
		printf("Largest for day %d: %d\n", y,*find_largest(temperatures[x],24));
		y++;
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool search(int a[][24], int n, int key) {

	int *p;

	for (p = a[0]; p < (a[0] + n); p++) {
		if (*p == key) {
			return true;
		}
	}

	// default return (no match)
	return false;
}

void initialize_array(int temperatures[][24]) {

	int *p;
	int a = 0;

	for (p = *temperatures; p < *temperatures + (7 * 24); p++) {

		if (a % 25 == 0) {
			*p = 1;		
		} else {
			*p = 0;
		}

		if (a == 1) {
			*p = 7;
		}
		a++;
	}
}

void print_row(int i, int temperatures[][24]) {

	int *p;

	for (p = temperatures[i]; p < temperatures[i] + (24); p++) {
		printf("%d ", *p);
	}
	printf("\n'Print Row' operation complete.\n");
}

void print_array(int temperatures[][24]) {

	int *p;
	int a = 0;

	for (p = *temperatures; p < *temperatures + (7 * 24); p++) {

		if (a % 24 == 0) {
			printf("\n");
		}

		printf("%d ", *p);
		a++;
	}

	printf("\n'Print Array' operation complete.\n");
}

int *find_largest(int a[], int n) {

	int i;
	int *max = &a[0];

	for (i = 0; i < n; i++) {
		if (a[i] > *max) {
			max = &a[i];		
		}
	}

	return max;
}
