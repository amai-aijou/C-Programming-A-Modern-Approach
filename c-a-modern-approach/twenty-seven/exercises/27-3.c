/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 27-3.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Nov  8 03:15:35 PM CST 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

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
	int i = 255;
	int ui = 255;

	printf("-------------------EXERCISE 27-3-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Assume i has the original type. Modify each so it works if i is changed to the new type\n\n");

	printf(COLOR_CYAN    "    unsigned int n;\n");
	printf(COLOR_CYAN    "    n &= n - 1;\n\n");

	printf(COLOR_MAGENTA "(a) printf(\"%%d\", i);		Original type: int			New type: int8_t\n");
	printf(COLOR_CYAN    "   Guess: " COLOR_RESET "\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf(              "                              %d", i);
	printf(              "                                  %" PRId8 "\n\n", (int8_t) i);

	printf(COLOR_MAGENTA "(b) printf(\"%%12.4d\", i);	Original type: int			New type: int32_t\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf(              "                     %12.4d", ui);
	printf(              "                                  %" PRId32 "\n\n", (int32_t) i);

	printf(COLOR_MAGENTA "(c) printf(\"%%-6o\", i);		Original type: unsigned int		New type: uint16_t\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf(              "                              %-6o", ui);
	printf(              "                               %" PRIo16 "\n\n", (uint16_t) i);

	printf(COLOR_MAGENTA "(d) printf(\"%%#x\", i);		Original type: unsigned int		New type: uint64_t\n");
	printf(COLOR_CYAN    "  Output: " COLOR_RESET); 
	printf(              "                             %#x", i);
	printf(              "                                 %#" PRIx64 "\n\n", (uint64_t) i);

	// Note: these look ugly as sign now, but it prints it in table format when compiled :)

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
