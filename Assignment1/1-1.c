/* Hans Prieto
 * CIS 314
 * Assignment 1-1
 */
#include <stdio.h>
#include <stdint.h>

unsigned int combine (unsigned int x, unsigned int y) {
	/* Returns an unsigned int consisting of byte 3 and 2 from x,
	 * and bytes 2 through 0 from y.
	 */
	uint32_t a, b, combined;

	// Shifts x to the right by 24 bits.
	a = x >> 24;

	// Shifts the result from a by 24 bits to the left.
	a = a << 24;

	// Shifts y to the left by 8 bits.
	b = y << 8;

	// Shifts the result from b by 8 bits to the right.
	b = b >> 8;

	// Uses bitwise OR to combine both a and b.
	combined = a | b;

	// Returns the combined result.
	return combined;
}

int main() {
	/* Prints out the result from calling the combine() function. */
	printf("0x%X\n", combine(0x12345678, 0xABCDEF00));
	printf("0x%x\n", combine(0xABCDEF00, 0x12345678));
	return 0;
}
