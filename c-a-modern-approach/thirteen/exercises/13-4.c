/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 13-4.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Mar 19 05:53:34 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <strings.h>
#include <ctype.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);
void zero_array(char str[], int n);
void print_array(char str[], int n);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n = 10;
	char str[11];
	int i;

	printf("Now testing functions (a)-(d). Please enter text as requested.\n");

	i = read_line_a(str, n);
	print_array(str, i);
	zero_array(str, n);

	i = read_line_b(str, n);
	print_array(str, i);
	zero_array(str, n);

	i = read_line_c(str, n);
	print_array(str, i);
	zero_array(str, n);

	i = read_line_d(str, n);
	print_array(str, i);
	zero_array(str, n);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

//(a) Skip Whitespace before storing input characters
int read_line_a(char str[], int n) {

	int ch, i = 0;

	printf("Input line (a): ");
	while ((ch = getchar()) != '\n') {

		if (i == 0 && ch == ' ') {
			continue;
		}
		if (i < n) {
			str[i++] = ch;
		}
	str[i] = '\0';
	}
	
	printf("\n");
	return i;
}

//(b) Stop reading at first whitespace char
int read_line_b(char str[], int n) {
	
	int ch, i = 0;

	printf("Input line (b): ");
	while ((ch = getchar()) != '\n') {

		if (isspace(ch) != 0) {
			break;
		}
		if (i < n) {
			str[i++] = ch;
		}
	str[i] = '\0';
	}
	
	// to remove any remaining characters (otherwise they'll stay in buffer and ruin next function call
	while (ch = getchar() != '\n') {
		continue;
	}

	printf("\n");
	return i;
}

//(c) Stop reading at first newline char, then store \n in string
int read_line_c(char str[], int n) {
	
	int ch, i = 0;

	printf("Input line (c): ");
	while (ch = getchar()) {

		if (ch == '\n') {
			str[i++] = ch;
			break;
		}
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	
	printf("\n");

	// to remove any remaining characters (otherwise they'll stay in buffer and ruin next function call
	while (ch = getchar() != '\n') {
		continue;
	}
	return i;
}

//(d) Leave behind chars it does not have room to store (chars which exceed n)
int read_line_d(char str[], int n) {
	
	int ch, i, x = 0;
	char leftovers[11];

	printf("Input line (d): ");
	for (i = 0; i < n; i++) {

		ch = getchar();

		if (ch == '\n') {
			break;
		}

		str[i] = ch;

	}
	str[i] = '\0';
	
	while ((ch = getchar()) != '\n') {
		leftovers[x] = ch;
		x++;
	}

	printf("Leftovers: ");
	print_array(leftovers, x);

	printf("\n");
	return i;
}

int read_line(char str[], int n) {
	
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	
	return i;
}

void zero_array(char str[], int n) {

	int i;
	
	for (i = 0; i < n; i++) {
		str[i] = 0;
	}
}

void print_array(char str[], int n) {
	
	int i;

	for (i = 0; i < n; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}
