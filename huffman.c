#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
struct MinHeapNode {
 char data;
 unsigned freq;
 struct MinHeapNode *left, *right;
};
struct MinHeap {
 unsigned size;
 unsigned capacity;
 struct MinHeapNode** array;
};
struct MinHeapNode* newNode(char data, unsigned freq) {
 struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct
MinHeapNode));
 temp->left = temp->right = NULL;
 temp->data = data;
 temp->freq = freq;
 return temp;
}
struct MinHeap* createMinHeap(unsigned capacity) {
 struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 minHeap->size = 0;
minHeap->capacity = capacity;
minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct
MinHeapNode*));
 return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
 struct MinHeapNode* t = *a;
 *a = *b;
 *b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx) {
 int smallest = idx;
 int left = 2 * idx + 1;
 int right = 2 * idx + 2;
 if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
 smallest = left;
 if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
 smallest = right;
 if (smallest != idx) {
 swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 minHeapify(minHeap, smallest);
 }
}
int isSizeOne(struct MinHeap* minHeap) {
 return (minHeap->size == 1);
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
 struct MinHeapNode* temp = minHeap->array[0];
 minHeap->array[0] = minHeap->array[minHeap->size - 1];
 --minHeap->size;
 minHeapify(minHeap, 0);
 return temp;
}
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
 ++minHeap->size;
 int i = minHeap->size - 1;
 while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
 minHeap->array[i] = minHeap->array[(i - 1) / 2];
 i = (i - 1) / 2;
 }
 minHeap->array[i] = minHeapNode;
}
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
 struct MinHeapNode *left, *right, *top;
 struct MinHeap* minHeap = createMinHeap(size);
 for (int i = 0; i < size; ++i)
 insertMinHeap(minHeap, newNode(data[i], freq[i]));
 while (!isSizeOne(minHeap)) {
 left = extractMin(minHeap);
 right = extractMin(minHeap);
 top = newNode('$', left->freq + right->freq);
 top->left = left;
 top->right = right;
 insertMinHeap(minHeap, top);
 }
 return extractMin(minHeap);
}
void printArr(int arr[], int n) {
 for (int i = 0; i < n; ++i)
 printf("%d", arr[i]);
}
void printCodes(struct MinHeapNode* root, int arr[], int top) {
 if (root->left) {
 arr[top] = 0;
 printCodes(root->left, arr, top + 1);
 }
 if (root->right) {
 arr[top] = 1;
 printCodes(root->right, arr, top + 1);
 }
 if (!(root->left) && !(root->right)) {
 printf("%c: ", root->data);
 printArr(arr, top);
 printf("\n");
 }
}
int main() {
 char data[] = {'A', 'B', 'C', 'D'};
 int freq[] = {5, 9, 12, 13};
 int size = sizeof(data) / sizeof(data[0]);
 struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
 int arr[MAX_TREE_HT], top = 0;
 printCodes(root, arr, top);
 char input[100];
 printf("\nEnter binary input to encode: ");
 scanf("%s", input);
 printf("\nDecoded Binary Input: ");
 struct MinHeapNode* temp = root;
 for (int i = 0; input[i] != '\0'; i++) {
 if (input[i] == '0')
 temp = temp->left;
 else if (input[i] == '1')
 temp = temp->right;
 if (temp->left == NULL && temp->right == NULL) {
 printf("%c", temp->data);
 temp = root;
 }
 }
 return 0;
}

