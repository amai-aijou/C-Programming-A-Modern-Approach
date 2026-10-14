/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 23-5.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Mon Oct 12 09:10:18 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
double compound_interest(double principal, double rate, double years, double frequency);
double compound_interest_euler(double principal, double rate, double years);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	double principal, rate, years, frequency, accumulated;

	printf("\n*********************\n");
	printf(" Interest Calculator");
	printf("\n*********************\n\n");

	printf("Please enter principal savings amount: ");
	scanf("%lf", &principal);
	printf("Number of years to save: ");
	scanf("%lf", &years);
	printf("Interest rate (per period): ");
	scanf("%lf", &rate);
	printf("Periods per year: ");
	scanf("%lf", &frequency);


	if (principal == 3.50) {
		printf("God DANGIT, it's the loch ness monstah!!! I ain't *got* tree fitty!\n");
		exit(EXIT_FAILURE);
	}

	accumulated = compound_interest(principal, rate, years, frequency);
	printf("Total accumulated: %lf\n\n", accumulated);


	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// Formula: A = P(1+(r/n)^(n * t)
double compound_interest(double principal, double rate, double years, double frequency) {

	return  principal * pow((1 + (rate/frequency)),(years * frequency));
}

// Continuous compounding, using euler's number. compounded as frequently as mathematically possible
// Formula: A = Pe^rt
double compound_interest_euler(double principal, double rate, double years) {

	double e = 2.718281828;

	return e;
}

/******************** KEY *********************
 *                                            *
 * P = principal                              *
 * r = rate of return (%)                     *
 * n = number of compound periods (frequency) *
 * t = number of years                        *
 *                                            *
 **********************************************/
