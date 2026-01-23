
#include <stdio.h>

int fact(int n);
int fact_new(int n);

int main(void) {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Factorial: %d\n", fact(num));
	printf("Factorial (new): %d\n", fact_new(num));

	return 0;
}


int fact(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int fact_new(int n) {
	int fact = 0;
	int i = 0;

	for (i = n; i > 1; i--) {
		n = n * (i-1);
	}

	return n;
}
