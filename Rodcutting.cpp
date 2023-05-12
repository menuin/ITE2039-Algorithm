//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void rod_cutting(int p[], int n);
void print_solution(int n, int s[]);
void sort_in_ascending_order(int keys[], int count);



int main() {

	int n;
	int* p;

	scanf("%d", &n);
	p = (int*)malloc(sizeof(int) * (n + 1));
	p[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &p[i]);
	}

	rod_cutting(p, n);

	free(p);

	return 0;
}

void rod_cutting(int p[], int n) {

	int q;
	int* r = (int*)malloc(sizeof(int) * (n + 1));
	int* s = (int*)malloc(sizeof(int) * (n + 1));

	r[0] = 0;
	s[0] = 0;


	for (int j = 1; j <= n; j++) {
		q = INT_MIN;
		for (int i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

	printf("%d\n", r[n]);
	print_solution(n, s);


	free(s);
	free(r);

}
void print_solution(int n, int s[]) {
	int* temp = (int*)malloc(sizeof(int) * n);
	int count = 0;
	int k = n;
	
	for (int i = 0; i < n; i++) {
		
		temp[i] = s[k];
		count++;
		k = k - s[k];

		if (k == 0) {
			break;
		}
	}
	

	sort_in_ascending_order(temp, count);

	free(temp);
}

void sort_in_ascending_order(int keys[], int count) {
	int temp, i, j, k;
	for (j = 0; j < count; j++)
	{
		for (k = j + 1; k < count; k++)
		{
			if (keys[j] > keys[k])
			{
				temp = keys[j];
				keys[j] = keys[k];
				keys[k] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		printf("%d ", keys[i]);
	}
}