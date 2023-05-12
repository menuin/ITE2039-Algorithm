//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void matrix_chain_order(int n, int* p);
void print_optimal_parenthesis(int** s, int i, int j);

int main() {
	
	int n;
	

	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		scanf("%d", &p[i]);
	}

	matrix_chain_order(n,p);

	free(p);

	return 0;
}

void matrix_chain_order(int n, int* p) {

	int j,q;

	int** m = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		m[i] = (int*)malloc(sizeof(int) * n);
	}
	int** s = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		s[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		m[i][i] = 0;
	}

	for (int l = 2; l < n+1 ; l++) {
		for (int i = 0; i < n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INT_MAX;

			for (int k = i; k < j; k++) {
				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", m[0][n - 1]);
	print_optimal_parenthesis(s, 0, 5);

	for (int i = 0; i < n; i++) {
		free(m[i]);
	}
	free(m);
	for (int i = 0; i < n; i++) {
		free(s[i]);
	}
	free(s);
}

void print_optimal_parenthesis(int** s, int a, int b) {

	if (a == b) {
		printf("%d ", a+1);
	}
	else {
		
		printf("( ");
		print_optimal_parenthesis(s, a, s[a][b]);
		print_optimal_parenthesis(s, s[a][b] + 1, b);
		printf(") ");	
	}
}