/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Oct 28 06:54:48 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdarg.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int max_int(int n, ...);
int max_int_new(int n, ...);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int a, b;

	printf("-------------------EXERCISE 26-1-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Rewrite max_int() so it takes a series of numbers, with a zero as the final terminator\n\n");

	printf(COLOR_MAGENTA "(a) max_int()\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	a = max_int(3, 10, 30, 20);
	printf("The largest int is %d\n\n", a);

	printf(COLOR_MAGENTA "(b) max_int_new()\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	b = max_int_new(5, 2, 40, 80, 40, 10, 30, 20, 0);
	printf("The largest int is %d\n\n", b);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int max_int_new(int n, ...) {

	va_list ap;

	int i, current, largest;
	int count = 1, args[100];

	largest = n;

	va_start(ap, n);

	while ((current = va_arg(ap, int)) != 0) {
		if (current > largest) {
			largest = current;
		}
	}

	va_end(ap);

	return largest;
}

int max_int(int n, ...) {

	va_list ap;

	int i, current, largest;

	va_start(ap, n);

	largest = va_arg(ap, int);

	for (i = 1; i < n; i++) {
		current = va_arg(ap, int);
		if (current > largest) {
			largest = current;
		}
	}

	va_end(ap);

	return largest;
}
