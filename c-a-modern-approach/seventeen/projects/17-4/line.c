#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
	char word[45];
	struct node *next;
};

struct node *line = NULL;
struct node *tail = NULL;

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

	struct node *p = line;

	while (p != NULL) {
		struct node *trash = p;
		p = p->next;
		free(trash);
	}

	line = NULL;

	line_len = 0;
	num_words = 0;
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

// 17-4: Adds a word by creating a new node in the linked list
// The list will need to be *reversed*, however, using a "tail" pointer
void add_word(const char *word) {

	char *p;

	struct node *new_node;

	new_node = calloc(1,sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}


	if (num_words > 0) {
		new_node->word[0] = ' ';
		line_len++;
	}

	//printf("Contents of word: |%s|\n", word);
	//printf("DEBUG - copying contents of word to new_node->word\n");
	strcat(new_node->word,word);
	//printf("DEBUG - copying contents of word to new_node->word - success\n");
	line_len += strlen(word);
	num_words++;

	if (tail == NULL) {
		new_node->next = tail->next;
		tail = new_node;
		line = new_node;
		return;
	}

	new_node->next = NULL;
	tail->next = new_node;
	tail = new_node;
}


int space_remaining(void) {
	return MAX_LINE_LEN - line_len;
}

/*********************************
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
**********************************/

void write_line(void) {
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;

	// Write words one by one until none are left
	while (num_words > 0) {
		printf("%s",line->word);
		fflush(stdout);
		
		if (num_words > 1) {
		// insert spacing
		spaces_to_insert = extra_spaces / (num_words - 1);
		for (j = 1; j <= spaces_to_insert + 1; j++) {
			putchar(' ');
		}
		extra_spaces -= spaces_to_insert;
		}

		// Dispose of node as it is destroyed
		struct node *trash = line;
		line = line->next;
		free(trash);

		//printf("DEBUG - Num of words before write_line(): %d", num_words);
		num_words--;
		//printf("DEBUG - Num of words after write_line(): %d", num_words);
		if (num_words == 0) {
			tail = NULL;
		}
	}

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
			puts(line->word);


		}
	}
}
