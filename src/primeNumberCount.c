#include <stdio.h>

int primeCount(int n);

int main() {

	int a;
	printf("Enter number": ");
	scanf_s("%d", &a);

	int b = primeCount(a);

	printf("%d", b);

	return 0;
}

int primeCount(int n) {
	int x = 2;
	int prime = 0;

	while (x <= n) {
		int count = 0;
		for (int i = 2; i <= x; i++) {
			if ((i != x) && (x % i == 0))
				count++;
		}
		if (count == 0)
			prime++;
		x++;
	}

	return prime;
}