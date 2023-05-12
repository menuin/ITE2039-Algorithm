//2019006171_김은민_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void HuffmanCode(char character[], int frequency[], int n);
void buildMinHeap(struct MinHeap* minHeap);
void minHeapify(struct MinHeap* minHeap, int index);
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
int isSizeOne(struct MinHeap* minHeap);
int isLeaf(struct MinHeapNode* root);
void printarr(int arr[], int n);
void printcodes(struct MinHeapNode* root, int arr[], int top,int n);
struct MinHeapNode* buildHuffmanTree(char character[], int frequency[], int n);


int main() {
	int n, s;
	char* character;
	int* frequency;

	scanf("%d", &n);

	character = (char*)malloc(sizeof(char) * n*4);
	frequency = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s %d", &character[i], &frequency[i]);
	}
	scanf("%d", &s);

	// print number of bits using fixed-length code
	int numofbits=ceil(log(n) / log(2));
	int count2 = 0;
	for (int i = 0; i < n; i++) {
		count2 += frequency[i] * numofbits;
	}
	printf("%d\n", count2);


	HuffmanCode(character, frequency, n);
	

	free(character);
	free(frequency);

	return 0;
}

void HuffmanCode(char character[], int frequency[], int n) {

	struct MinHeapNode* root = buildHuffmanTree(character, frequency, n);

	int arr[100];
	int top = 0;
	
	printcodes(root, arr, top,n);
}



struct MinHeapNode {
	
	char character;
	int frequency;

	struct MinHeapNode* left, * right;
};

struct MinHeapNode* newNode(char character, int frequency) {
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->character = character;
	temp->frequency = frequency;

	return temp;
}

struct MinHeap {
	int size;
	int capacity;

	struct MinHeapNode** array;
};





struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

	return minHeap;
}

void buildMinHeap(struct MinHeap* minHeap) {
	int k = minHeap->size - 1;
	for (int i = (k - 1) / 2; i >= 0; i--) {
		minHeapify(minHeap, i);
	}
}

void minHeapify(struct MinHeap* minHeap, int index) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
		smallest = left;
	}
	if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
		smallest = right;
	}
	if (smallest != index) {
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
		minHeapify(minHeap, smallest);
	}
}

struct MinHeap* createAndBuildMinHeap(char character[], int frequency[], int n) {
	struct MinHeap* minHeap = createMinHeap(n);
	for (int i = 0; i < n; i++) {
		minHeap->array[i] = newNode(character[i], frequency[i]);
	}
	minHeap->size = n;
	buildMinHeap(minHeap);

	return minHeap;
}




struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	//temp = min heap
	struct MinHeapNode* temp = minHeap->array[0];
	//마지막 node를 첫번째로 옮기고 다시 minheapify
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}




struct MinHeapNode* buildHuffmanTree(char character[], int frequency[], int n) {
	struct MinHeapNode* left, * right, * top;

	struct MinHeap* minHeap = createAndBuildMinHeap(character,frequency,n);

	while (!isSizeOne(minHeap)) {
		//extract the two minimum frequency items
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		// '$' is a special value for internal nodes (not used)
		top = newNode('$', left->frequency + right->frequency);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}

	//한개 남은 node extract
	return extractMin(minHeap);
}






void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}
int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}
int isLeaf(struct MinHeapNode* root) {
	return !(root->left) && !(root->right);
}

void printcodes(struct MinHeapNode* root, int arr[], int top, int n) {
	
	static int count = 0;
	static int count2 = 0;

	

	if (root->left) {
		arr[top] = 0;
		printcodes(root->left, arr, top + 1,n);
		
		
		
	}
	if (root->right) {
		arr[top] = 1;
		printcodes(root->right, arr, top + 1,n);
		
		
	
	}
	
	if (isLeaf(root)) {
		
		count = count + root->frequency * top;
		count2++;

		if (count2 == n) {
			printf("%d\n", count);
			
		}

	}
	
	
}
