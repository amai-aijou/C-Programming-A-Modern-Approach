
/******************************************
 * Name: addfrac.c
 * Purpose: 
 * Author: jolson
 * Date: Fri Apr 18 09:53:10 PM CDT 2025
 ******************************************/

#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;
	char op;
	int op_err = 0;

	printf("Enter first fractions: ");
	scanf("%d /%d", &num1, &denom1);

	while (op != '+') {
				  // 	|| op != '-' || op != '*' || op != '/') {
		printf("Enter an operator (+|-|*|/): ");
		scanf("%s", &op);
		printf("Current fucked-up value of op: %d", op);

		if (op_err >= 1) {
			printf("ERROR: Invalid Operator. Allowed operators: (+|-|*|/)\n");
		}
		op_err++;	
	}

	printf("Enter second fraction: ");
	scanf("%d /%d", &num2, &denom2);

	switch (op) {
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;
			printf("The sum is %d/%d\n", result_num, result_denom);
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			printf("The sum is %d/%d\n", result_num, result_denom);
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			printf("The sum is %d/%d\n", result_num, result_denom);
			break;
		case '/':
			result_num = num1 * denom2;
			result_denom = num2 * denom1;
			printf("The sum is %d/%d\n", result_num, result_denom);
			break;
		default:
			printf("ERROR: Invalid Operator\n");
							//  
	}

	return 0;
}

