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

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 18-1-------------------\n\n");
	printf("Q. For each of the following declarations, identify the:\n"
		   "  * Storage Class\n"
		   "  * Type Qualifiers\n"
		   "  * Type Specifiers\n"
		   "  * Declarators\n"
		   "  * Initializers\n\n");

	printf("(a) static char **lookup(int level);\n");
	printf("	%-18s : %s\n", "Storage Class", "static"); // * Storage Class: static\n"
printf(		   "  * Type Qualifiers: -\n"
		   "  * Type Specifiers: char\n"
		   "  * Declarators: **lookup(int level), level\n"
		   "  * Initializers:\n\n");

	printf("(b) volatile unsigned long io_flags;\n"
		   "  * Storage Class: -\n"
		   "  * Type Qualifiers: volatile\n"
		   "  * Type Specifiers: unsigned long\n"
		   "  * Declarators: io_flags\n"
		   "  * Initializers: -\n\n");

	printf("(c) extern char *file_name[MAX_FILES], path[];\n"
		   "  * Storage Class: extern\n"
		   "  * Type Qualifiers: -\n"
		   "  * Type Specifiers: char\n"
		   "  * Declarators: *file_name[MAX_FILES], path[]\n"
		   "  * Initializers:\n\n");
	
	printf("(d) static const char token_buf[] = "";\n"
		   "  * Storage Class: static\n"
		   "  * Type Qualifiers: const\n"
		   "  * Type Specifiers: char\n"
		   "  * Declarators: token_buf[]\n"
		   "  * Initializers: ""\n\n");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

