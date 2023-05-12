//2019006171_±Ë¿∫πŒ_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

	int* keys;
	int numofkeys; 
	int key;

	
	scanf("%d", &numofkeys);

	keys =(int*)malloc(sizeof(int) * numofkeys);


	for (int i = 0; i < numofkeys; i++) {
		scanf("%d", &keys[i]);
		
	}

	

	for (int j = 1; j < numofkeys; j++) {
		key = keys[j];
		int i = j - 1;

		while (i >=0 && keys[i] < key) {
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = key;
	}

	for (int i = 0; i < numofkeys; i++) {
		printf("%d\n", keys[i]);
	}

	
	free(keys);

	return 0;
}