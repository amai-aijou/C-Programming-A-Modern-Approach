/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon May 25 03:55:25 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

struct {
	union {
		char a, b;
		int c;
	} d;
	int e[5];
} f, *p = &f;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("-------------------EXERCISE 17-5-------------------\n");
	printf("Which of the following statements are legal?\n\n");

	// (a)
	p->d.b = ' ';
	printf("(a) Q: p->b = ' ';\n");
	printf("    A: ILLEGAL\n");
	printf("  Why: p->b doesn't exist! p->d.b must be used, instead.\n");
	printf("  ex.: p->d.b: |%c|\n\n", p->d.b);

	// (b)
	p->e[3] = 10;
	printf("(b) Q: p->e[3] = 10;\n");
	printf("    A: LEGAL\n");
	printf("  Why: Perfectly fine, simply sets array element 4 of e[5] to 10.\n");
	printf("  ex.: p->e[3]: %d\n\n", p->e[3]);

	// (c)
	(*p).d.a = '*';
	printf("(c) Q: (*p).d.a = '*';\n");
	printf("    A: LEGAL\n");
	printf("  Why: The * operator has a lower precedence than -> and . so it needs parentheses.\n");
	printf("       It will not compile properly without it (I tried!)\n");
	printf("  ex.: (*p).d.a: %c\n\n", (*p).d.a);

	// (d)
	p->d.c = 20;
	printf("(d) Q: p->d->c = 20;\n");
	printf("    A: ILLEGAL\n");
	printf("  Why: p->d->c is like saying *p.*d.c which makes no sense. p->d.c will work instead.\n");
	printf("  ex.:p->d.c: %d\n\n", p->d.c);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
