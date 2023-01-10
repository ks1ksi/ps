#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int jari(n) {
	int a = n / 1000;
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;
	return a + b + c + d;

}

int checkself(n) {
	int counter = 1;
	for (int i = 1; i <= n; i++) {
		if (jari(n - i) == i) {
			counter--;
			break;
		}
	}
	return counter;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (checkself(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}