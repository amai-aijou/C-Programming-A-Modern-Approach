/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-21.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 17 05:48:19 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("\n-------------------EXERCISE 16-21------------------\n");
	printf("What are the integer values of the enum constants in each declaration?\n\n");
	// (a)
	enum {NUL, SOH, STX, ETX};
	printf("(a) enum {NUL, SOH, STX, ETX} alpha;\n");
	printf("    output: 0,  1,   2,   3\n");
	printf("    ex. - SOH: %d\n\n", SOH);


	// (b)
	enum {VT = 11, FF, CR} beta;
	printf("(b) enum {VT = 11, FF, CR} beta;\n");
	printf("    output: 11,    12, 13\n");
	printf("    ex. - FF: %d\n\n", FF);

	// (c)
	enum {SO = 14, SI, DLE, CAN = 24, EM} gamma;
	printf("(c) enum {SO = 14, SI, DLE, CAN = 24, EM} gamma;\n");
	printf("    output: 14,    15, 16,   24,     25\n");
	printf("    ex. - SI: %d | EM: %d\n\n", SI, EM);

	// (d)
	enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC} delta;
	printf("(d) enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC} delta;\n");
	printf("    output: 45,    46, 47,   37,       38,  39\n");
	printf("    ex. - ACK: %d | ETC: %d\n\n", ACK, ETB);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
