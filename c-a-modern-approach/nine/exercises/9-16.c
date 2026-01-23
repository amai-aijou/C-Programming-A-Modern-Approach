int fact(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int fact_new(int n) {
	return n <= 1 ? 1 : n * fact(n-1);
}
