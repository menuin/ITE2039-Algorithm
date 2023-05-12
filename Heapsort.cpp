//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void heapsort(int keys[], int k, int size);
void buildmaxheap(int keys[], int size);
void maxheapify(int keys[], int size, int i);
void swap(int* a, int* b);

int main() {

	int n;
	int k;
	int* keys;


	scanf("%d %d", &n, &k);

	keys = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &keys[i]);
	}

	heapsort(keys, k, n);

	free(keys);


	return 0;
}

void heapsort(int keys[], int k, int size) {
	buildmaxheap(keys, size);


	int n = size;

	while (size > n - k) {

		swap(&keys[0], &keys[size - 1]);

		printf("%d ", keys[size - 1]);
		size--;

		maxheapify(keys, size, 0);

	}

	printf("\n");
	for (int i = 0; i < n - k; i++) {
		printf("%d ", keys[i]);
	}




}

void buildmaxheap(int keys[], int size) {



	for (int i = size / 2 - 1; i >= 0; i--) {
		maxheapify(keys, size, i);
	}

}

void maxheapify(int keys[], int size, int i) {

	int largest = i;



	if (2 * i + 1 < size && keys[2 * i + 1] > keys[largest]) {
		largest = 2 * i + 1;

	}

	if (2 * i + 2 < size && keys[largest] < keys[2 * i + 2]) {
		largest = 2 * i + 2;


	}



	if (i != largest) {
		swap(&keys[largest], &keys[i]);

		maxheapify(keys, size, largest);
	}



}

void swap(int* a, int* b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
