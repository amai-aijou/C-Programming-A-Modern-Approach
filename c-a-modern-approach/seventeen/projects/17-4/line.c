#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
	char word[45];
	struct node *next;
};

struct node *line = NULL;

/*********************************/

// char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

/*********************************
void clear_line(void) {
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}
**********************************/

// 17-4: Cleans line by deleting all nodes, then making *line = NULL
void clear_line(void) {

	struct node *p;

	while (p != NULL) {
		struct node *trash = p;
		p = p->next;
		free(trash);
	}

	line = NULL;

	line_len = 0;
	num_words = 0;
}

// 17-4: Adds a word by creating a new node in the linked list
// The list will need to be *reversed*, however, using a "tail" pointer
void add_word(const char *word) {

	if (num_words > 0)
}

/*********************************
void add_word(const char *word) {
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len+1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}
**********************************/

int space_remaining(void) {
	return MAX_LINE_LEN - line_len;
}

void write_line(void) {
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}
/*********************************
void flush_line(void) {
	if (line_len > 0)
			puts(line);
}
**********************************/

void flush_line(void) {

	struct node *p;

	if (line_len > 0) {
		for (p = line; p != NULL; p = p->next) {
		// Add logic for iterating through line->word (another loop)
		}
	}
}

/******** SCHEMA ********
 *
 * this is a test.
 *
 * first = test(.) -> a -> is -> this -> NULL
 *
 *
