/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 23-8.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri Oct  9 02:26:15 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
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
int numchar(const char *s, char ch);
int reverse_numchar(const char *s, char ch);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char str[] = "Form follows function.";

	printf("-------------------EXERCISE 23-8-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Use strchr to make this function:\n\n");
	
	printf(COLOR_CYAN    "  int numchar(const char *s, char ch);\n\n");

	printf(COLOR_MAGENTA "(1) strchr\n");
	printf(COLOR_CYAN    " Output: " COLOR_RESET); 
	printf("%d\n\n", numchar(str, 'o'));
	printf(COLOR_CYAN     "   Exp.:" COLOR_RESET " I wrote the numchar() function in the last exercise so I wouldn't have to do it twice :)\n\n");

	printf(COLOR_MAGENTA "(2) strrchr\n");
	printf(COLOR_CYAN    " Output: " COLOR_RESET); 
	printf("%d\n", reverse_numchar(str, 'o'));
	printf(COLOR_CYAN     "   Exp.:" COLOR_RESET " Yes and no. You can't do it *just* with the original string, but you can add new termination points to a temp string!\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int numchar(const char *s, char ch) {

	int count = 0;
	char *p;

	if ((p = strchr(s, ch)) != NULL) {

		count++;

		while ((p = strchr(p + 1, ch)) != NULL) {
			count++;
		}
	}

	return count;
}

int reverse_numchar(const char *s, char ch) {

	int count = 0;
	char *p, tmpstr[200];

	strcpy(tmpstr, s);


	if ((p = strrchr(tmpstr, ch)) != NULL) {
		// p now points to "Form follows Xunction.";
		*p = '\0';
		// tmpstr = "Form follows X.";

		count++;

		while ((p = strrchr(tmpstr, ch)) != NULL) {
			*p = '\0';
			count++;
		}
	}

	return count;
}

/* DEBUG
		printf("DEBUG - p:     %d | *p:     %c\n", p, *p);
		printf("DEBUG - p - 1: %d | *p - 1: %d\n", (p - 1), *(p - 1));
*/
