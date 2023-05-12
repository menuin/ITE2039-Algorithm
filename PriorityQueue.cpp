// 2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void increasekey(int heap[], int index);
void swap(int &a, int &b);
void maxheapify(int keys[], int size, int index);


int main() {

	int end = 0;
	int choice;
	int heap[200000];
	int numcom=0;
	int largervalues[200000];
	int numlargervalues = 0;
	int changed;
	int substitute;
	int index;

	while (end==0) {
		scanf("%d", &choice);

		if (choice == 1) {
			scanf("%d", &heap[numcom + 1]);
			numcom++;

			index = numcom;
			increasekey(heap, index);
		}
		if (choice == 2) {
			largervalues[numlargervalues] = heap[1];
			numlargervalues++;
			heap[1] = heap[numcom];
			numcom--;

			maxheapify(heap, numcom, 1);
		}
		if (choice == 3) {
			scanf("%d %d", &changed, &substitute);

			if (changed <= numcom) {
				heap[changed] = substitute;
				int parent = changed / 2;

				if (parent >= 1 && heap[changed] > heap[parent]) {

					increasekey(heap, changed);
					
				
				}
				else {
					maxheapify(heap, numcom, changed);
				}
			}
		}

		if (choice == 0) {
			for (int i = 0; i < numlargervalues; i++) {
				printf("%d ", largervalues[i]);
			}
			printf("\n");
			for (int i = 1; i <= numcom; i++) {
				printf("%d ", heap[i]);
			}
			end = 1;
		}


		
	}

	return 0;
}



void increasekey(int heap[], int index) {
	int parent = index / 2;
	while ((parent>=1)&&(heap[parent]<heap[index])){
		swap(heap[parent], heap[index]);

		index = parent;
		parent = index / 2;
	}
}

void maxheapify(int heap[], int size, int index) {
	int largest = index;

	if (2 * index <=size && heap[2 * index]>heap[largest]) {
		largest = 2 * index;
	}
	if (2 * index + 1 <= size && heap[2 * index + 1] >= heap[largest]) {
		largest = 2 * index + 1;
	}
	if (index != largest) {
		swap(heap[index], heap[largest]);
		maxheapify(heap, size, largest);
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}