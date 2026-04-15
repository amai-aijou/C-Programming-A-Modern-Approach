/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 13-6.c (originally 12-1.c)
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Mar  5 07:08:16 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

#define MAX 100

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void read_user_input(char a[*], int *n);
void print_array(char a[*], int *n);
void print_array_backwards_subscript(char a[*], int *n);
void print_array_backwards_arith(char a[*], int *n);
void read_user_input_arith(char a[*], int *n);
void reverse(char *message);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char a[MAX] = "this is a test.";
	int n = 15;

//	read_user_input(a, &n);
//	read_user_input_arith(a, &n);

	print_array(a, &n);

//	print_array_backwards_subscript(a, &n);

//	print_array_backwards_arith(a, &n);

	reverse(a);

	print_array(a, &n);
	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void read_user_input(char a[], int *n) {

	char ch;

	printf("Enter a message: ");

	while ((ch = getchar()) != '\n') {

		a[*n] = ch;
		(*n)++;
	}
}

void read_user_input_arith(char a[], int *n) {

	char *p = a;
	char ch;

	printf("Enter a message: ");

	while ((ch = getchar()) != '\n') {

		*(p + *n) = ch;
		(*n)++;	
	}
}

void print_array(char a[], int *n) {

	int i;

	printf("Printing array: ");
	for (i = 0; i < *n; i++) {
		printf("%c", a[i]);
	}
	printf("\n\n");
}

void print_array_backwards_subscript(char a[], int *n) {

	int i;

	for (i = *n; i >= 0; i--) {
		printf("%c", a[i]);
	}
	printf(" :si lasreveR\n\n");
}

void print_array_backwards_arith(char a[], int *n) {

	char *p;

	for (p = a + *n; p >= a; p--) {
		printf("%c", *p);
	}
	printf(" :si lasreveR\n");
	printf("(Pointer Arithmethic)\n\n");
}

// New one for Chapter 13-16
void reverse(char *message) {

	char *p, *q;
	char ch;
	int n = 0;

	// Move q to the last character of the string
	for (p = message; *p != '\0'; p++) {
		n++;	
	}

	printf("n: %d\n", n);

	q = message + (n - 1);

	for (p = message; p != q ; p++, q--) {

		ch = *p;
		*p = *q;
		*q = ch;
	}
}
