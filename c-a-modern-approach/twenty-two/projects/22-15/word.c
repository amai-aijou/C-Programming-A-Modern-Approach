#include <stdio.h>
#include "word.h"

int read_char(FILE *fpIn) {
	int ch = fgetc(fpIn);

	return (ch == '\n' || ch == '\t') ? ' ' : ch;
/* OLD CODE
	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
*/
}

int read_word(FILE *fpIn, char *word, int len) {
	int ch, pos = 0;

	while ((ch = read_char(fpIn)) == ' ')
		;
	while (ch != ' ' && ch != EOF) {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char(fpIn);
	}
	word[pos] = '\0';
	return pos;
}
