#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(x) {
	int a = 1;
	for (int i = 1; i <= x; i++) {
		a = a * i;
	}
	return a;
}




int main() {
	int a, b, nk=0;
	scanf("%d %d", &a, &b);
	nk = factorial(a) / factorial(b) / factorial(a - b);
	printf("%d", nk);

	return 0;
}