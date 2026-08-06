/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-16.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Wed Aug  5 01:05:10 PM CDT 2026
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

typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

union {
	struct {
		WORD ax, bx, cx, dx;
	} word;
	struct {
		BYTE al, ah, bl, bh, cl, ch, dl, dh;
	} byte;
} regs;

union {
	struct {
		DWORD eax, ebx, ecx, edx;
	} dword;
	struct {
		WORD ax;
		WORD wordPad1[1];
		WORD bx;
		WORD wordPad2[1];
		WORD cx;
		WORD wordPad3[1];
		WORD dx;
		WORD wordPad4[1];
	} word;
	struct {
		BYTE al;
		BYTE ah;
		BYTE byteP1[2];
		BYTE bl;
		BYTE bh;
		BYTE byteP2[2];
		BYTE cl;
		BYTE ch;
		BYTE byteP3[2];
		BYTE dl;
		BYTE dh;
		BYTE byteP4[2];
	   
	} byte;
} regs32;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {
	

	printf("-------------------EXERCISE 20-16-------------------\n\n");
	printf(COLOR_MAGENTA "Q. Turn the 16-bit CPU register union from 20-3 into 64-bit.\n"
			             "     to do this, add eax, ebx, ecx, edx as 32-bit DWORD-typed members...\n"
						 "     ...but remember to leave the most-significant bit halves as blank padding so the members line up!\n\n");

	printf(COLOR_CYAN	 "  Size of unsigned long: %d\n", sizeof(unsigned long) * 8);
	printf(				 "  Size of unsigned int: %d\n", sizeof(unsigned int) * 8);
	printf(				 "  Size of unsigned short: %d\n", sizeof(unsigned short) * 8);
	printf(				 "  Size of unsigned char: %d\n\n", sizeof(unsigned char) * 8);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
