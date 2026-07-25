/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 20-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Thu Jul 23 09:22:39 PM CDT 2026
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

#define MK_COLOR(x,y,z) ((x) | (y << 8) | (z << 16))

#define GET_RED(x) ((x) & 0xFF)
#define GET_GREEN(x) ((x >> 8) & 0xFF)
#define GET_BLUE(x) ((x >> 16) & 0xFF)

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	long int color;
	short red, green, blue;

	printf("-------------------EXERCISE 20-4 & 20-5------------\n\n");
	printf(COLOR_MAGENTA "Create macro MK_COLOR and have it return a long with three parameters: REd, GREEN, BLUE\n"
			             "These parameters will take up the last three bytes.\n"
						 "Note: Remember x64 islittle-endian, so Red will be the last byte!\n\n");

	printf(COLOR_MAGENTA "(20-4)\n");
	printf(COLOR_CYAN    " Guess: " COLOR_RESET "#define MK_COLOR(x,y,z) ((x) |(y << 8) | (z << 16))\n");
	printf(COLOR_CYAN    "Output: ");

	color = MK_COLOR(255,255,255);
	printf("%d\n\n", color);


	printf(COLOR_MAGENTA "(20-5)\n");
	printf(COLOR_CYAN    " Guess: " COLOR_RESET "#define GET_RED(x) ((x) &= 0xFF)\n");
	printf(COLOR_CYAN    "Output: ");

	red = GET_RED(color);
	green = GET_GREEN(color);
	blue = GET_BLUE(color);
	printf(COLOR_RESET "GET_RED:   %d\n", red);
	printf("        GET_GREEN: %d\n", green);
	printf("        GET_BLUE:  %d\n", blue);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
