#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, h = 99, a = 0, b = 0, c = 0;
	scanf("%d", &n);
	if (n < 100) {
		h = n;
	}
	else {
		for (int i = 100; i <= n; i++) {
			c = i % 10;
			b = (i % 100) / 10;
			a = (i - 10 * b - c) / 100;
			if ((c - b) == (b - a)) {
				h++;
			}
		}
	}
	printf("%d", h);
	return 0;
}