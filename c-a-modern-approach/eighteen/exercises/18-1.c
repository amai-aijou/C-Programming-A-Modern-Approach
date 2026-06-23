/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 18-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Jun 20 06:14:55 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_RESET "\033[1;0m"

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-1-------------------\n\n");
	printf(COLOR_MAGENTA "Q. For each of the following declarations, identify the:\n"
		   COLOR_CYAN "  * Storage Class\n"
		   "  * Type Qualifiers\n"
		   "  * Type Specifiers\n"
		   "  * Declarators\n"
		   "  * Initializers\n\n");

	printf(COLOR_MAGENTA "(a) static char **lookup(int level);\n"
		   COLOR_CYAN "  * Storage Class: " COLOR_RESET "static\n"
		   COLOR_CYAN "  * Type Qualifiers: " COLOR_RESET "-\n"
		   COLOR_CYAN "  * Type Specifiers: " COLOR_RESET "char\n"
		   COLOR_CYAN "  * Declarators: " COLOR_RESET "**lookup(int level), level\n"
		   COLOR_CYAN "  * Initializers: " COLOR_RESET "-\n\n");

	printf(COLOR_MAGENTA "(b) volatile unsigned long io_flags;\n"
		   COLOR_CYAN "  * Storage Class: " COLOR_RESET "-\n"
		   COLOR_CYAN "  * Type Qualifiers: " COLOR_RESET "volatile\n"
		   COLOR_CYAN "  * Type Specifiers: " COLOR_RESET "unsigned long\n"
		   COLOR_CYAN "  * Declarators: " COLOR_RESET "io_flags\n"
		   COLOR_CYAN "  * Initializers: " COLOR_RESET "-\n\n");

	printf(COLOR_MAGENTA "(c) extern char *file_name[MAX_FILES], path[];\n"
		   COLOR_CYAN "  * Storage Class: " COLOR_RESET "extern\n"
		   COLOR_CYAN "  * Type Qualifiers: " COLOR_RESET "-\n"
		   COLOR_CYAN "  * Type Specifiers: " COLOR_RESET "char\n"
		   COLOR_CYAN "  * Declarators: " COLOR_RESET "*file_name[MAX_FILES], path[]\n"
		   COLOR_CYAN "  * Initializers: " COLOR_RESET "-\n\n");

	printf(COLOR_MAGENTA "(d) static const char token_buf[] = "";\n"
		   COLOR_CYAN "  * Storage Class: " COLOR_RESET "static\n"
		   COLOR_CYAN "  * Type Qualifiers: " COLOR_RESET "const\n"
		   COLOR_CYAN "  * Type Specifiers: " COLOR_RESET "char\n"
		   COLOR_CYAN "  * Declarators: " COLOR_RESET "token_buf[]\n"
		   COLOR_CYAN "  * Initializers: " COLOR_RESET "\"\"\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

