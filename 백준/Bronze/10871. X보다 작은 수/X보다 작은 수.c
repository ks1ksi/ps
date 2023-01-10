#include <stdio.h>

int main() {
	int n, x, a[10000];

	scanf("%d %d", &n, &x);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	for (int k = 0; k < n; k++)
		if (a[k] < x)
			printf("%d ", a[k]);
	return 0;
}