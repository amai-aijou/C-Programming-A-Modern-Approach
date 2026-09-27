/* Formats a file of text */

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) {
	char word[MAX_WORD_LEN+2];
	int word_len;

	FILE *fpIn, *fpOut;

	// Open read file
	if ((fpIn = fopen(argv[1], "rb")) == NULL) {
		printf("Error: Could not open %s for reading.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Open write file
	if ((fpOut = fopen(argv[2], "wb")) == NULL) {
		printf("Error: Could not open %s for writing.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;) {
		word_len = read_word(fpIn, word, MAX_WORD_LEN+1);
		if (word_len == 0) {
			flush_line(fpOut);
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(fpOut);
			clear_line();
		}
		add_word(word);
	}
}
