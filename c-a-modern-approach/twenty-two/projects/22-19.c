/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 22-19.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Oct  1 07:00:32 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIN_OS 1
#define NIX_OS 0

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool detect_os(FILE *source_fp);
void text_switcher(FILE *source_fp, FILE *dest_fp, bool output_OS);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(int argc, char *argv[]) {

	int i = 0, n = 0;
	bool output_OS = NIX_OS;
	char output_file[100];

	FILE *source_fp, *dest_fp;

	// Open input file 
	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// detect_OS detects the input OS, then assigns the opposing OS value to output_OS
	output_OS = detect_os(source_fp);

	// copy string to output_file variable in case they didn't provide an output file
	strcpy(output_file, argv[1]);

	// If output file not provided, attempt to create .win/.nix based on results of detect_os
	if (argc != 3) {
		if (argc == 2) {
			printf("No output file provided. Attempting to create filename."
					"If it exists, kiss it goodbye!\n");
			
			if (output_OS == WIN_OS) {
				strcat(output_file, ".win");
			} else {
				strcat(output_file, ".nix");
			}
			printf("Output file has been successfully crafted as: %s\n\n", output_file);
		} else {
			fprintf(stderr, "usage: ./22-19 winfile nixfile\n");
			exit(EXIT_FAILURE);
		}
	}

	// Open file #2
	if ((dest_fp = fopen(output_file, "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", output_file);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	text_switcher(source_fp,dest_fp,output_OS);
	printf("Operation complete.\n");

	fclose(source_fp);
	fclose(dest_fp);

	return 0;
}
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
bool detect_os(FILE *source_fp) {

	char buffer[3000];

	fread(buffer, sizeof(buffer[0]), 3000, source_fp);
	fseek(source_fp, 0, SEEK_SET); //Moves the file position back to the beginning after!

	if (strstr(buffer, "\r\n")) {
		printf("Windows File detected. Converting to Linux!\n\n");
		return NIX_OS;
	} else {
		printf("Linux File detected. Converting to Windows (but why would you want to!?)\n\n");
		return WIN_OS;
	}

}

void text_switcher(FILE *source_fp, FILE *dest_fp, bool output_OS) {

	int ch;
	char insert_cr = '\r', insert_lf = '\n';

	while (ch != EOF) {

		while (((ch = fgetc(source_fp)) != '\n') && (ch != '\r') && (ch != EOF )){
			fputc(ch, dest_fp);
		}

		if (output_OS == WIN_OS) {
			fputc(insert_cr,dest_fp); 
			fputc(insert_lf,dest_fp);
		} else {
			fputc(insert_lf,dest_fp); 
		}

		while (((ch = fgetc(source_fp)) == '\n') || (ch == '\r' )){
			// Empty loop to clear out the newline chars, as we already inserted them!
		}
			
	}

	return;
}
