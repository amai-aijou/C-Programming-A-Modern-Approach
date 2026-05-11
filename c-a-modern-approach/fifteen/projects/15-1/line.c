#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

int num_lines = 0; // 15-1 update: variable to determine whether line is even or odd

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
	int bias; //15-1

	extra_spaces = MAX_LINE_LEN - line_len;

	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ') {
			putchar(line[i]);
		} else {
			if (num_lines % 2 == 0) {

				// 15-1 Project: Alternate justification between beginning and end of line
				// the number of gaps is (num_words - 1), which is our denominator in the division
				// we have to 'nudge' the remainder using a Ceiling Function, which is "numerator + (denominator - 1) / denominator"
				// this gives us num_words - 2
				spaces_to_insert = extra_spaces / (num_words - 1);
			} else {
				spaces_to_insert = (extra_spaces + (num_words - 2)) / (num_words - 1);
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
