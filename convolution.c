#include <stdio.h>
#include <stdlib.h>
void repetitionEncode(int input[], int output[], int len) {
 for (int i = 0; i < len; i++) {
 output[2 * i] = input[i];
 output[2 * i + 1] = input[i];
 }
}
void repetitionDecode(int received[], int decoded[], int len) {
 for (int i = 0; i < len; i++) {
 int count0 = 0, count1 = 0;
 for (int j = 0; j < 2; j++) {
 if (received[i * 2 + j] == 0) {
 count0++;
 } else {
 count1++;
 }
 }
 if (count0 > count1) {
 decoded[i] = 0;
 } else {
 decoded[i] = 1;
 }
 }
}
int main() {
int inputLength;
 printf("Enter the length of binary data: ");
 scanf("%d", &inputLength);
 int *input = (int *)malloc(inputLength * sizeof(int));
 printf("Enter binary data (0s and 1s separated by spaces): ");
 for (int i = 0; i < inputLength; i++) {
 scanf("%d", &input[i]);
 }
 int encoded[2 * inputLength];
 repetitionEncode(input, encoded, inputLength);
 printf("Encoded Data: ");
 for (int i = 0; i < 2 * inputLength; i++) {
 printf("%d ", encoded[i]);
 }
 printf("\n");
 int decoded[inputLength];
 repetitionDecode(encoded, decoded, inputLength);
 printf("Decoded Data: ");
 for (int i = 0; i < inputLength; i++) {
 printf("%d ", decoded[i]);
 }
 printf("\n");
 free(input); 
 return 0;
}
