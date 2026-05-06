#include <stdio.h>
#include "word.h"

int read_char(void) {
	int ch = getchar();

	return (ch == '\n' || ch == '\t') ? ' ' : ch;
/* OLD CODE
	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
*/
}

// called as read_word(word, MAX_WORD_LEN + 1)
int read_word(char *word, int len) {
	int ch, pos = 0;

	while ((ch = read_char()) == ' ')
		;
	while (ch != ' ' && ch != EOF) {
		if (pos < len) {
			word[pos++] = ch;
		}


		ch = read_char();
	}
	word[pos] = '\0';

	if (pos >= (len)) {
		word[len-1] = '*';
	}

	return pos;
}

//15-2: Move the below section from main() to read_word()
//		if (word_len > MAX_WORD_LEN)
//			word[MAX_WORD_LEN] = '*';
