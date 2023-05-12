//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fastest_way(int** a, int** t, int e1, int e2, int x1, int x2, int n);

int main() {
	int n, e1, e2, x1, x2;
	int** a;
	int** t;

	scanf("%d\n", &n);
	scanf("%d %d\n", &e1, &e2);
	scanf("%d %d\n", &x1, &x2);

	a = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		a[i] = (int*)malloc(sizeof(int) * n);
	}
	t = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		t[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[0][i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[1][i]);
	}
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &t[0][i]);
	}
	for (int i = 0; i < n-1; i++) {
		scanf("%d", &t[1][i]);
	}

	
	fastest_way(a, t, e1, e2, x1, x2, n);

	for (int i = 0; i < 2; i++) {
		free(a[i]);
	}
	free(a);
	for (int i = 0; i < 2; i++) {
		free(t[i]);
	}
	free(t);

	return 0;
}

void fastest_way(int** a, int** t, int e1, int e2, int x1, int x2, int n) {
	int** s;
	int** l;
	int time;
	int key;

	s = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		s[i] = (int*)malloc(sizeof(int) * n);
	}
	l = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		l[i] = (int*)malloc(sizeof(int) * n);
	}

	s[0][0] = e1 + a[0][0];
	s[1][0] = e2 + a[1][0];

	for (int j = 1; j < n; j++) {
		if (s[0][j - 1] <= s[1][j - 1] + t[1][j - 1]) {
			s[0][j] = s[0][j - 1] + a[0][j];
			l[0][j] = 1;
		}
		else {
			s[0][j] = s[1][j - 1] + t[1][j - 1]+a[0][j];
			l[0][j] = 2;
		}
		if (s[1][j - 1] <= s[0][j - 1] + t[0][j - 1]) {
			s[1][j] = s[1][j - 1] + a[1][j];
			l[1][j] = 2;
		}
		else {
			s[1][j] = s[0][j - 1] + t[0][j - 1]+a[1][j];
			l[1][j] = 1;
		}
	}

	if (s[0][n - 1] + x1 <= s[1][n - 1] + x2) {
		time = s[0][n - 1] + x1;
		key = 1;
	}
	else {
		time = s[1][n - 1] + x2;
		key = 2;
	}

	printf("%d\n", time);

	int* temp = (int*)malloc(sizeof(int) * n);
	temp[0] = key;
	int k = key;
	for (int i = 1; i < n;i++) {
		k = l[k-1][n - i];
		temp[i] = k;
	}


	for (int i = 1; i <=n; i++) {
		printf("%d %d\n", temp[n-i], i);
	}


	free(temp);

	for (int i = 0; i < 2; i++) {
		free(s[i]);
	}
	free(s);
	for (int i = 0; i < 2; i++) {
		free(l[i]);
	}
	free(l);
}