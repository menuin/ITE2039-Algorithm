//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void counting(int** arr, int a, int b, int* keys, int n);

int main() {
	int n;
	int m;
	int k;


	scanf("%d %d %d", &n, &m, &k);

	int* keys = (int*)malloc(sizeof(int) * n);
	int** arr = (int**)malloc(sizeof(int*) * k);
	for (int i = 0; i < k; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &keys[i]);
	}

	for (int i = 0; i < k; i++) {
		counting(arr, arr[i][0], arr[i][1],keys,n);
	}

	free(arr[0]);
	free(arr);
	free(keys);

	return 0;
}

void counting(int **arr, int a, int b, int *keys, int n){
	int count = 0;
	
	for (int i = 0; i < n; i++) {
		if (keys[i] >= a && keys[i] <= b) count++;
	}
	printf("%d\n", count);
}