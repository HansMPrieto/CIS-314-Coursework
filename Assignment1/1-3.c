/* Hans Prieto
 * CIS 314
 * Assignment 1-3
 */
#include <stdio.h>

int evenBit(unsigned int x) {
	/* Determines if x has at least one bit 
	 * with a value of 1 at an even index.
	 */

	// Uses bitwise AND to isolate even bits.
	unsigned int even_bits = x & 0x55555555;

	// Uses logical NOT determine if x has at least one bit with a value of 1 at an even index.
	return !!even_bits;
}

int main() {
	/* Prints out the result from calling the evenBit() function. */
	printf("%d\n", evenBit(0x1));
	printf("%d\n", evenBit(0x2));
	printf("%d\n", evenBit(0x3));
	printf("%d\n", evenBit(0x4));
	printf("%d\n", evenBit(0xFFFFFFFF));
	printf("%d\n", evenBit(0xAAAAAAAA));
	printf("%d\n", evenBit(0x55555555));
	return 0;
}
