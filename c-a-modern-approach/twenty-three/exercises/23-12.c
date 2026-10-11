/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 23-12.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Oct 10 03:36:56 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *redup(char *s);
char *relwr(char *s);
int reicmp(char *s1, char *s2);
char *rerev(char *s);
char *reset(char *s, char ch);
int relen(char *s);
char *recpy(char *s1, char *d2);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char *p;				// a
	char s1[5+1] = "test1";	// a
	char s2[5+1] = "test2";	// b
	char s3[5+1] = "test2";	// b
	char s4[5+1] = "TEST3";	// c
	char s5[5+1] = "ABCDE";	// d
	char s6[5+1] = "ABCDE";	// d

	printf("-------------------EXERCISE 23-12-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Build all of these functions (yes, ALL)\n\n");

	printf(COLOR_MAGENTA "  (a) strdup(s)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	p = redup(s1);
	printf(              "      s1 before redup: %s\n", s1);
	printf(              "       p  after redup: %s\n\n", p);
	free(p);

	printf(COLOR_MAGENTA "  (b) stricmp(s1,s2)\n");
	printf(COLOR_CYAN    "     Output: \n" COLOR_RESET); 
	switch (reicmp(s2,s3)) {
		case  1: printf( "       s2 is greater than s3\n\n");
				 break;
		case -1: printf( "       s2  is  less than  s3\n\n");
				 break;
		case  0: printf( "       s2  is  equal  to  s3\n\n");
				 break;
	}

	printf(COLOR_MAGENTA "  (c) strlwr(s)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	printf(              "      s4 before relwr: %s\n", s4);
	relwr(s4);
	printf(              "       s4 after relwr: %s\n\n", s4);

	printf(COLOR_MAGENTA "  (d) strrev(s)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	printf(              "      s5 before rerev: %s\n", s5);
	rerev(s5);
	printf(              "       s5 after rerev: %s\n", s5);

	printf(COLOR_MAGENTA "  (e) strset(s,ch)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	printf(              "       s6  before set: %s\n", s1);
	recpy(s1,s2);
	printf(              "       s1  after  set: %s\n", s1);

	printf(COLOR_MAGENTA "  BONUS: relen(s)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	printf(              "      Length: %d\n\n", relen(s4));

	printf(COLOR_MAGENTA "  BONUS: recpy(s)\n");
	printf(COLOR_CYAN    "    Output: \n" COLOR_RESET); 
	printf(              "       s1 before copy: %s\n", s1);
	recpy(s1,s2);
	printf(              "       s1 after  copy: %s\n", s1);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *redup(char *s) {

	int n = relen(s);
	char *p ;

	p = malloc(n * (sizeof(char) + 1));
	recpy(p,s);

	return p;
}

int reicmp(char *s1, char *s2) {

	int i = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {

		if (toupper(s1[i]) > toupper(s2[i])) {
			return 1;
		} else if (toupper(s1[i]) < toupper(s2[i])) {
			return -1;
		} else {
			continue;
		}
	}

	return 0;
}

char *relwr(char *s) {

	int i = 0;

	for (i = 0; s[i] != '\0'; i++) {
		s[i] = tolower(s[i]);
	}

	return s;
}

char *rerev(char *s) {

	int i = 0;
	int n = (relen(s) - 1);
	char *p = redup(s);

	for (i = 0; n >= 0; i++,n--) {
		s[i] = p[n];
	}

	free(p);

	return s;
}

char *reset(char *s, char ch) {

	int n = strlen(s);
	
	for ( ; n > 0; n--) {

		s[n-1] = ch;
	}

	return s;
}

int relen(char *s) {

	int i = 0;
	char *p;

	for (p = s; *p != '\0'; p++) {
		i++;
	}

	return i;
}

char *recpy(char *s1, char *s2) {

	int i = 0;

	for (i = 0; s2[i] != '\0'; i++) {

		s1[i] = s2[i];
	}
	s1[i] = '\0';

	return s1;
}
