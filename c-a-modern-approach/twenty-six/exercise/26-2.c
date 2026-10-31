/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Oct 29 11:51:08 AM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int count_digits(int n);
int simple_printf(char *str, ...);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int n = 0;
	char *ing = "ing";

	printf("-------------------EXERCISE 26-2-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Write printf() from scratch! You only need to do %d (thankfully)\n\n");

	printf(COLOR_CYAN    "    simple_printf(char *str, ...)\n\n");

	printf(COLOR_CYAN    "Joe's Version:\n" COLOR_RESET); 

	n = simple_printf("%dtest%d", -1, 1);
	simple_printf("\t\t\t#Prints %d characters\n", n);

	n = simple_printf("test%c", '2');
	simple_printf("\t\t\t#Prints %d characters\n", n);

	n = simple_printf("test%s", "ing");
	simple_printf("\t\t\t#Prints %d characters\n", n);

	n = simple_printf("Did %s %d pass?: %c", "test", 1, 'Y');
	simple_printf("\t#Prints %d characters\n", n);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// Simplified printf that can only handle %d and %d (so far, at least!). returns number of chars printed to screen
int simple_printf(char *str, ...) {

	va_list ap;
	int ch, i = 0, j = 0, count = 0, n, ibuf = 0;
	char nbuf[10], *sbuf;
	bool nNeg;

	va_start(ap, str);

	while ((ch = str[i++]) != '\0') {

		if (ch != '%') {
			fputc(ch, stdout);
			count++;
		} else {

			switch (ch = str[i++]) {
				case 'c':
					n = va_arg(ap, int);
					fputc(n,stdout);
					count++;
					break;
				case 'd':
					n = va_arg(ap, int);

					// add a negative sign if number is less than zero!
					if (n < 0) {
						fputc('-', stdout);
						n = abs(n);
						count++;
					}

					while (n != 0) {
						nbuf[ibuf++] = (n % 10);
						n /= 10;
					}

					while (ibuf != 0) {
						fputc((nbuf[(ibuf-- - 1)] + '0'),stdout);
						count++;
					}
					break;
				case 's':
					sbuf = va_arg(ap, char *);
					
					while (sbuf[j] != '\0') {
						fputc(sbuf[j++],stdout);
						count++;
					}
					break;
			}
		}
	}

	va_end(ap);

	return count;
}
