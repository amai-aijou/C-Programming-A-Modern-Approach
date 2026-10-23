/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 25-2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Oct 22 05:19:12 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int mbcheck(const char *s);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int a, b, c, d, e;

	printf("-------------------EXERCISE 25-2-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Show the value returned by mbcheck for each of these\n");
	printf(COLOR_RESET   "  Note: Shift-JIS(ja_JP.sjis) must be installed on your machine!\n\n");


	if (setlocale(LC_CTYPE, "ja_JP.sjis") == NULL) {
		perror("setlocale");
		exit(EXIT_FAILURE);
	}
	printf(COLOR_CYAN    "    LC_CTYPE: %s\n\n", setlocale(LC_CTYPE, NULL));

	printf(COLOR_MAGENTA "(a) \\x05\\x87\\x80\\x36\\xed\\xaa\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	a = mbcheck("\x05\x87\x80\x36\xed\xaa");
	printf("a: %d\n\n", a);

	printf(COLOR_MAGENTA "(b) \\x20\\xe4\\x50\\x88\\x3f\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	b = mbcheck("\x20\xe4\x50\x88\x3f");
	printf("b: %d\n\n", b);

	printf(COLOR_MAGENTA "(c) \\xde\\xad\\xbe\\xef\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	c = mbcheck("\xde\xad\xbe\xef");
	printf("c: %d\n\n", c);

	printf(COLOR_MAGENTA "(d) \\x8a\\x60\\x92\\x74\\x41\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	d = mbcheck("\x8a\x60\x92\x74\x41");
	printf("d: %d\n\n", d);

	printf(COLOR_MAGENTA "(e) \\xff\\x60\\x92\\x74\\x41\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	e = mbcheck("\xff\x60\x92\x74\x41");
	printf("e: %d\n\n", d);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int mbcheck(const char *s) {

	int n;

	for (mblen(NULL, 0); ; s += n) {
		if ((n = mblen(s, MB_CUR_MAX)) <= 0) {
			return n;
		}
	}
}
