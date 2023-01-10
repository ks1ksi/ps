#include <stdio.h>

int main() {
	int x, y, sum=0, a[13];
	a[0] = 0;
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= 7; i++) {
		if (i % 2 == 1)
			a[i] = 31;
		else
			a[i] = 30;
	}
	a[2] = 28;
	for (int i = 8; i <= 12; i++) {
		if (i % 2 == 1)
			a[i] = 30;
		else
			a[i] = 31;
	}
	for (int i = 1; i <= x; i++) {
		sum += a[i-1];
	}
	sum += y;

	if (sum % 7 == 1)
		printf("MON");
	else if (sum % 7 == 2)
		printf("TUE");
	else if (sum % 7 == 3)
		printf("WED");
	else if (sum % 7 == 4)
		printf("THU");
	else if (sum % 7 == 5)
		printf("FRI");
	else if (sum % 7 == 6)
		printf("SAT");
	else
		printf("SUN");


	return 0;
}