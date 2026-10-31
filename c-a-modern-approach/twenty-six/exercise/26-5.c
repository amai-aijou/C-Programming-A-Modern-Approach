/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 26-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Oct 30 03:43:04 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *vstrcat(const char *first, ...);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char *catString;

	printf("-------------------EXERCISE 26-5-------------------\n\n");
	printf(COLOR_MAGENTA "Q. all args are strings except the last, a null pointer cast to char *.\n"
			             "   returns a pointer to a dynamically-allocated string with a concat of all args.\n"
						 "   If no memory available, return null pointer.\n\n");

	printf(COLOR_CYAN    "    char *vstrcat(const char *first, ...);\n\n");

	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 

	catString = vstrcat("hajime", "ma", "shite", "!!", NULL);

	printf("Concatenated string: %s\n\n", catString);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *vstrcat(const char *first, ...) {

	va_list ap, ap2;
	char *va_str;
	int charCount = 0, i = 0;
	char *catString;

	va_start(ap, first);
	va_copy(ap2, ap);

	while ((va_str = va_arg(ap, char *)) != NULL) {

		for (i = 0; va_str[i] != '\0'; i++) {
			charCount++;
		}
	}

	if ((catString = malloc(charCount * sizeof((char) + 1))) == NULL) {
		printf("DEBUG - Not enough memory available/memory could not be allocated\n");
		return NULL;
	}

	strcat(catString, first);
	while ((va_str = va_arg(ap2, char *)) != NULL) {
		strcat(catString,va_str);
	}

	va_end(ap);
	va_end(ap2);
	
	return catString;
}
