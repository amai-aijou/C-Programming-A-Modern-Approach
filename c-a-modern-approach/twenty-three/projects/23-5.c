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

struct user_data {
	double total_principal;
	double total_balance;
	double gain_percent;
	double gain_dollars;
} user1;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void compound_interest(void);
void compound_interest_euler(void);
void info(void);
void menu(void);
void loch_ness_check(double principal);
void user_stats(void);
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char selection;

	info();

	while (selection != 'q') {
		printf("Please enter a selection: ");
		scanf(" %c", &selection);
		//selection = fgetc(stdin);
		switch (selection) {

			case 'd': compound_interest();
					  break;
			case 'e': compound_interest_euler();
					  break;
			case 'i': info();
					  break;
			case 'm': menu();
					  break;
			case 'u': user_stats(); 
					  break;
		}
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// Discrete compounding, where interest is applied as (rate/frequency) 
// Formula: A = P(1+(r/n)^(n * t)
void compound_interest(void) {

	double principal, rate, years, frequency, accumulated;

	printf("Please enter principal savings amount: ");
	scanf("%lf", &principal);
	loch_ness_check(principal);
	user1.total_principal += principal;

	printf("Number of years to save: ");
	scanf("%lf", &years);

	printf("Interest rate (per period): ");
	scanf("%lf", &rate);

	printf("Periods per year: ");
	scanf("%lf", &frequency);

	accumulated = principal * pow((1 + (rate/frequency)),(years * frequency));
	printf("Total accumulated: %lf\n\n", accumulated);
	user1.total_balance += accumulated;
	user1.gain_dollars += accumulated - principal;
	user1.gain_percent = (user1.total_balance / user1.total_principal) - 1.0;
}

// Continuous compounding, using euler's number. compounded as frequently as mathematically possible
// Formula: A = Pe^rt | e: 2.718281828
void compound_interest_euler(void) {

	double principal, rate, years, accumulated;

	printf("Please enter principal savings amount: ");
	scanf("%lf", &principal);
	loch_ness_check(principal);
	user1.total_principal += principal;

	printf("Number of years to save: ");
	scanf("%lf", &years);

	printf("Interest rate (per period): ");
	scanf("%lf", &rate);

	accumulated = principal * pow((2.718281828),(rate * years));
	printf("Total accumulated: %lf\n\n", accumulated);
	user1.total_balance += accumulated;
	user1.gain_dollars += accumulated - principal;
	user1.gain_percent = (user1.total_balance / user1.total_principal) - 1.0;
}

/******************** KEY *********************
 *                                            *
 * P = principal                              *
 * r = rate of return (%)                     *
 * n = number of compound periods (frequency) *
 * t = number of years                        *
 *                                            *
 **********************************************/

void info(void) {

	printf("\n*********************\n");
	printf(" Interest Calculator");
	printf("\n*********************\n\n");

	printf("Calculates interest. Enter (m) for menu\n\n");
}

void menu(void) {

	printf("SELECTIONS\n");
	printf("d - Discrete Interest Calculator\n");
	printf("e - Continuous Interest Calculator\n");
	printf("m - menu\n");
	printf("q - quit\n\n");
}

void loch_ness_check(double principal) {

	if (principal == 3.50) {
		printf("...now, it was about that time, I noticed this girl scout was three storyies tall and breathed fire!\n");
		printf("It wasn't a girl scout, it was the Loch Ness monstah!!!\n");
		printf("I'm not givin you tree fitty, Loch Ness Monster!\n\n");
		exit(EXIT_FAILURE);
	}
}

void user_stats(void) {

	printf("\n***********\n");
	printf(" User Stats");
	printf("\n***********\n\n");

	printf("Total principal: %lf\n", user1.total_principal);
	printf("Total balance: %lf\n", user1.total_balance);
	printf("Total Gain (%): %lf\n", user1.gain_percent);
	printf("Total Gain ($): %lf\n\n", user1.gain_dollars);
}
