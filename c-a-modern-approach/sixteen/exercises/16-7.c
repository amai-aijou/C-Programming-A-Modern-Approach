/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-7.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri May 15 02:18:53 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
} f  = {8, 12},
  f1 = {1,  2},
  f2 = {2,  5};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct fraction lowest_terms(struct fraction f);
struct fraction add_fractions(struct fraction f1, struct fraction f2);
struct fraction subtract_fractions(struct fraction f1, struct fraction f2);
struct fraction multiply_fractions(struct fraction f1, struct fraction f2);
struct fraction divide_fractions(struct fraction f1, struct fraction f2);
int GCD(int n, int d);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("(a) Fraction: %d/%d\n", f.numerator, f.denominator);
	f = lowest_terms(f);
	printf("    After GCD: %d/%d\n\n", f.numerator, f.denominator);

	f = add_fractions(f1,f2);
	printf("(b) Add 1/2 + 2/5: %d/%d\n\n", f.numerator, f.denominator);

	f = subtract_fractions(f1,f2);
	printf("(c) Subtract 1/2 - 2/5: %d/%d\n\n", f.numerator, f.denominator);

	f = multiply_fractions(f1,f2);
	printf("(d) Multiply 1/2 * 2/5: %d/%d\n\n", f.numerator, f.denominator);

	f = divide_fractions(f1,f2);
	printf("(3) Divide 1/2 / 2/5: %d/%d\n\n", f.numerator, f.denominator);

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a)
struct fraction lowest_terms(struct fraction f) {

	int gcd = GCD(f.numerator,f.denominator);

	f.numerator /= gcd;
	f.denominator /= gcd;

	return f;
}


// (b)
struct fraction add_fractions(struct fraction f1, struct fraction f2) {
	
	struct fraction f;

	f.denominator = f1.denominator * f2.denominator;
	f.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
	
	return f = lowest_terms(f);
}

// (c)
struct fraction subtract_fractions(struct fraction f1, struct fraction f2) {
	
	struct fraction f;

	f.denominator = f1.denominator * f2.denominator;
	f.numerator = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
	
	return f = lowest_terms(f);
}

// (d)
struct fraction multiply_fractions(struct fraction f1, struct fraction f2) {
	
	struct fraction f;

	f.denominator = f1.denominator * f2.denominator;	
	f.numerator = f1.numerator * f2.numerator;
	
	return f = lowest_terms(f);
}

// (e)
struct fraction divide_fractions(struct fraction f1, struct fraction f2) {
	
	struct fraction f;

	f.denominator = f1.denominator * f2.numerator;	
	f.numerator = f1.numerator * f2.denominator;
	
	return f = lowest_terms(f);
}

// For use with (a); determines the Greatest Common Denominator
int GCD(int n, int d) {
	int r;

	while (n != 0) {
		r = d % n;
		d = n;
		n = r;
	}

	return d;
}
