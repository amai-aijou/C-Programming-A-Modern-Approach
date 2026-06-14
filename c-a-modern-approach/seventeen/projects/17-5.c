/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Jun 13 06:31:00 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STORAGE 100

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int read_line(char str[], int n);
void print_array(char *str[], int n);
int compare(const void *p, const void *q);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char ch;
	char *storage[MAX_STORAGE];
	char word[20];
	int maxChars = 20;
	int i = 0;
	int length;

	for (;;) {
		printf("Enter word: ");

		if ((length = (read_line(word,maxChars))) == 0) {
			break;
		}

		storage[i] = malloc(length + 1);
		strcpy(storage[i], word);

		i++;
	}

	printf("As entered: ");
	print_array(storage, i);
	qsort(storage, i, sizeof(char *),compare);
	printf("\nAfter sorting: ");
	print_array(storage, i);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
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

int compare(const void *p, const void *q) {

	const char *p1 = *(const char **) p;
	const char *q1 = *(const char **) q;

	if (strcmp(p1,q1) < 0) {
		return -1;
	} else if (strcmp(p1,q1) == 0) {
		return 0;
	} else {
		return 1;
	}
}
		
void print_array(char *str[], int n) {

	int i;

	for (i = 0; i < n; i++) {

		if (i ==0) {
			printf("%s", str[i]);
			continue;
		}

		printf(" %s", str[i]);
	}

	printf("\n");
}
