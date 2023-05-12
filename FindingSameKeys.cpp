//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int m;
	int* a;
	int* b;

	scanf("%d %d", &n, &m);
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		int found = 0;
		int j = 0;

		while ((found == 0) && (j < m)) {
			found = (a[i] == b[j]);
			j++;
		}

		if (found !=0) {
			count++;
		}
	}

	printf("%d", count);
	free(a);
	free(b);
	return 0;
}