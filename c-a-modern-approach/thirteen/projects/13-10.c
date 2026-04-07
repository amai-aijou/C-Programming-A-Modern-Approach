/******************************************
 * Name: 13-10.c
 * Purpose: 
 * Author: amai-aijou
 * Date: Sun Sep 21 03:25:01 PM CDT 2025
 ******************************************/

#include <stdio.h>
#include <ctype.h>

void reverse_name(char *name);
void read_line(char *name, int n);

int main(void) {

	char ch;
	char first;
	char name[100];

	printf("Enter a first and last name: ");
	read_line(name, 100);

	reverse_name(name);

	return 0;
}

void reverse_name(char *name) {

	char *p = name;
	char first;

	while (*p == ' ') {
		p++;
	}

	first = *p;	
	
	while (*p != ' ') {
		p++;
	}

	while (*p == ' ') {
		p++;
	}

	for (; *p != '\0'; p++) {
		printf("%c", *p);
	}

	printf(", %c.\n", first);
}

void read_line(char *name, int n) {

	char ch;
	int i = 0;
	
	while ((ch = getchar()) != '\n') {
		if (i < n) {
			name[i++] = ch;
		}
	}

	name[i] = '\0';
}
