// 2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mergesort(int keys[], int p, int r);
void merge(int keys[], int p, int q, int r);

int main() {
	int* keys;
	int numofkeys;

	scanf("%d", &numofkeys);
	keys = (int*)malloc(sizeof(int) * numofkeys);

	for (int i = 0; i < numofkeys; i++) {
		scanf("%d", &keys[i]);
	}

	

	mergesort(keys, 0, numofkeys - 1);

	for (int i = 0; i < numofkeys; i++) {
		printf("%d\n", keys[i]);
	}

	free(keys);
	return 0;
}

void mergesort(int keys[], int p, int r) {
	

	if (p < r) {
		int q = (p + r) / 2;

		mergesort(keys, p, q);
		mergesort(keys, q + 1, r);

		merge(keys, p, q, r);
	}



}

void merge(int keys[], int p, int q, int r) {
	
	int n = r - p + 1;
	int* temp;
	temp = (int*)malloc(sizeof(int) * n);
	
	
	int i = p;
	int j = q + 1;
	int k = 0;

	while (i <= q && j < r + 1){
		
		if (keys[i] >= keys[j]) {

			temp[k++] = keys[i++];
			
		}
		else {
			temp[k++] = keys[j++];
			
		}
	

	}
	 
	while (i <= q) {
		temp[k++] = keys[i++];

	}
	
	while (j < r + 1) {
		temp[k++] = keys[j++];
	}

	for (int i = 0; i < k; i++) {
		keys[p + i] = temp[i];
	}

	free(temp);



}