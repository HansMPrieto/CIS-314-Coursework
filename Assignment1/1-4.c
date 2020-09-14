/* Hans Prieto
 * CIS 314
 * Assignment 1-4
 */
#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main() {
	printInt(6);	// Output: 06 00 00 00
	printFloat(6);	// Output: 00 00 c0 40 
	printShort(6);	// Output: 06 00
	printLong(6);	// Output: 06 00 00 00 00 00 00 00
	printDouble(6);	// Output: 00 00 00 00 00 00 18 40 
	
	// I noticed that each of the test functions had different outputs. 
	// This was caused by how much memory is used to print each type.
	// Int is 1 byte.
	// Float is 1 byte.
	// Short is 4 bits.
	// Long is 2 bytes.
	// Double is 2 bytes.
} 
