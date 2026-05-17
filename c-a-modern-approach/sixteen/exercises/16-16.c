/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-16.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat May 16 09:05:35 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum ages {JOE = 37, SUJI = 8, MILU = 8};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("\n-------------------EXERCISE 16-3-------------------\n");
	printf("Which of the following statements about enumeration constants are true?\n\n");

	// (a)
	printf("(a) Q: An enum constant may represent any integer specified by the programmer.\n");
	printf("    A: TRUE\n");
	printf(" Why?: The programmer may assign any integer to an enum constant element\n");
	printf("   ex: The 'ages' enum has been explicitly assigned a value of 37: %d\n\n", JOE);

	// (b)
	printf("(b) Q: Enum constant have exactly the same properties as constants created using #define.\n");
	printf("    A: FALSE\n");
	printf(" Why?: They're similar, but different. For example, #define is substituted by the pre-processor\n"
		   "       before compile, and isn't subject to scope rules (enums are!)\n\n");
	
	// (c)
	printf("(c) Q: Enum constants have the values 0,1,2... by default.\n");
	printf("    A: TRUE\n");
	printf(" Why?: If you don't otherwise specify, enum constants will start at 0 and go up as integers\n");
	printf("   ex: The 'suit' enum has been declared without an integer, and should start at 0: %d\n\n", CLUBS);

	// (d)
	printf("(d) Q: All constants in an enum must have different values.\n");
	printf("    A: FALSE\n");
	printf(" Why?: You can set the same value to multiple constants\n");
	printf("   ex: The enum 'ages' has two entries that are the same age: %d %d\n\n", SUJI, MILU);

	// (e)
	printf("(e) Q: Enum constants may be used as integers in expressions.\n");
	printf("    A: TRUE\n");
	printf(" Why?: While they work differently under the hood, they function similar to  #define statements and represent integer values\n");
	printf("   ex: Total from 'ages' enum: %d\n\n", (JOE + SUJI + MILU));

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
