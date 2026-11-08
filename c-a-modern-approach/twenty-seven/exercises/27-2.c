/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 27-2.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Nov  8 02:05:01 PM CST 2026
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

/*************************************/
// Tells the system we are using the x86_64 chipset
// (or that we support x86_64, as some 64-bit chipsets may not support it in certain circumstances)
#define __x86_64__

// If x86_64, define __WORDSIZE as 64; otherwise, use 32
#if defined __x86_64__ && !defined __ILP32__
# define __WORDSIZE	64
#else
# define __WORDSIZE	32
#define __WORDSIZE32_SIZE_ULONG		0
#define __WORDSIZE32_PTRDIFF_LONG	0
#endif

// If __WORDSIZE is 64, the minimum necessary sizes change
#if __WORDSIZE== 64
#define INT32_C(n) n 
#define UINT32_C(n) n ## U
#define INT64_C(n) n ## L
#define UINT64_C(n) n ## UL
#else
#define INT32_C(n) n 
#define UINT32_C(n) n ## U
#define INT64_C(n) n ## LL
#define UINT64_C(n) n ## ULL
#endif

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {


	printf("-------------------EXERCISE 27-2-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Write parameterized macros for each of the below. int & long are 32 bits, and long long is 64 bits.\n");
	printf(COLOR_CYAN    "   Hint: You can use ## to add the suffix\n");

	printf(COLOR_CYAN    "    INT32_C(n)\n");
	printf(COLOR_CYAN    "    UINT32_C(n)\n");
	printf(COLOR_CYAN    "    INT64_C(n)\n");
	printf(COLOR_CYAN    "    UINT64_C(n)\n\n");

	printf(COLOR_CYAN    "  Output: \n" COLOR_RESET); 
	printf(              "      32-bit  int: %d\n", INT32_C(100)); 
	printf(              "      32-bit uint: %d\n", UINT32_C(100)); 
	printf(              "      64-bit  int: %d\n", INT64_C(100)); 
	printf(              "      64-bit uint: %d\n", UINT64_C(100)); 

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
