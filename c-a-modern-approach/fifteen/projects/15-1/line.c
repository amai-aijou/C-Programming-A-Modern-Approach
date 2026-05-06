#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

// 15-1 update: variable to determine whether line is even or odd
int num_lines = 0;

void clear_line(void) {
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

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

int space_remaining(void) {
	return MAX_LINE_LEN - line_len;
}

void write_line(void) {
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;
//	printf("----------------------------------------------\n");
//	printf("num_lines: %d\n", num_lines);
//	printf("extra_spaces: %d | DEBUG: line_len: %d | MAX_LINE_LEN: %d\n", extra_spaces, line_len, MAX_LINE_LEN );

	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ') {
			putchar(line[i]);
		} else {
			// 15-1 Project: Alternate justification between beginning and end of line
			if (num_lines % 2 == 0) {
				spaces_to_insert = extra_spaces  / (num_words - 1);
//				printf("\nDEBUG: spaces to insert = (extra_spaces / (num_words - 1): %d | extra_spaces: %d | num_words: %d\n", spaces_to_insert, extra_spaces, num_words);
			} else {
				spaces_to_insert = (extra_spaces) / (num_words - 2);
//				printf("\nDEBUG: spaces to insert (extra_spaces / (num_words - 1): %d | extra_spaces: %d | num_words: %d\n", spaces_to_insert, extra_spaces, num_words);
			}
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
	num_lines++;
}

void flush_line(void) {
	if (line_len > 0) {
		puts(line);
		num_lines++;
	}
}



// 9 / 6 ( 9 - 1)

// insert behavior when line is even:
// spaces_to_insert = 10 / (5 - 1) = 2
// 8 / (4 - 1) = 2
// 6 / (3 - 1) = 3
// 3 / (2 - 1) = 3
// 0 / 0
/*
10 + 1 / 5 - 1 = 1
9 + 1 / 4 - 1 = 2
7 + 1 / 3 - 1 = 2
5 + 1 / 2 - 1 = 6
*/
// spaces_to_insert = 10 / 5 - 2 = 3
// 7 / 4 - 2 = 3
// 4 / 3 - 1 = 2
// 2 / 2 - 1 = 2

// insert behavior when line is odd:
// spaces_to_insert = 10 / (5 - 2) = 3
// 7 / (4 - 2) = 3
// 4 / (3 - 2) = 4
// 0 / (2 - 2) = UNDEFINED (crashes)
