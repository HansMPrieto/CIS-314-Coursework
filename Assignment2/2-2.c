/* Hans Prieto
 * CIS 314
 * Assignment 2-2
 */
#include <stdio.h>

unsigned int extract(unsigned int x, int i) { 
	/* Returns byte i of x sign extended to 
	 * 32 bits.
	 */

	// Shifts i to the left by 3 bits.
	int i_times_8 = i << 3;

	// Determines how many bits to the left x
	// needs to be shifted.
	int shift  = 24 - i_times_8;

	// Shifts x to the left by the result that 
	// was calculated from the previous step.
	int shifted_x = x << shift;

	// Shifts x to the right by 24 bits to get
	// the extracted byte i extended to 32 bits.
	unsigned int extracted = shifted_x >> 24;

	// Returns the extracted byte. 
	return extracted;
}

int main() {
	/* Prints out the result from calling the 
	 * extract() function.
	 */
	printf("0x%08X\n", extract(0x12345678, 0));
	printf("0x%08X\n", extract(0xABCDEF00, 2));
	return 0;
}
