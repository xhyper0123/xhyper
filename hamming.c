#include <stdio.h>
void calculateParityBits(int data[7]) {
 data[0] = (data[2] + data[4] + data[6]) % 2;
 data[1] = (data[2] + data[5] + data[6]) % 2;
 data[3] = (data[4] + data[5] + data[6]) % 2;
}
int correctError(int code[7]) {
 int errorBit = 0;
 errorBit += (code[0] + code[2] + code[4] + code[6]) % 2;
 errorBit += (code[1] + code[2] + code[5] + code[6]) % 2 * 2;
 errorBit += (code[3] + code[4] + code[5] + code[6]) % 2 * 4;
 if (errorBit != 0) {
 printf("Error detected in bit: %d\n", errorBit);
 printf("Correcting the received code...\n");
 code[errorBit - 1] = (code[errorBit - 1] + 1) % 2;
 } else {
 printf("No error detected in the received code.\n");
 }
 return errorBit;
}
int main() {
 int data[4];
 int encodedData[7];
 printf("Enter 4 bits of data to encode (separated by spaces): ");
 for (int i = 0; i < 4; i++) {
 scanf("%d", &data[i]);
 }
 encodedData[2] = data[0];
 encodedData[4] = data[1];
 encodedData[5] = data[2];
 encodedData[6] = data[3];
 calculateParityBits(encodedData);
 printf("Encoded data with parity bits: ");
 for (int i = 0; i < 7; i++) {
 printf("%d", encodedData[i]);
 }
 printf("\n");
 printf("Simulating an error in the received code...\n");
 encodedData[3] = (encodedData[3] + 1) % 2;
 int errorBit = correctError(encodedData);
 printf("Corrected code: ");
 for (int i = 0; i < 7; i++) {
 printf("%d", encodedData[i]);
 }
 printf("\n");
 int decodedData[4];
 decodedData[0] = encodedData[2];
 decodedData[1] = encodedData[4];
 decodedData[2] = encodedData[5];
 decodedData[3] = encodedData[6];
 printf("Decoded data: ");
 for (int i = 0; i < 4; i++) {
 printf("%d", decodedData[i]);
 }
 printf("\n");
 return 0;
}
