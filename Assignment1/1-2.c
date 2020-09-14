/*Hans Prieto
 * CIS 314
 * Assignment 1-2
 */
#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b) {
	/* Replaces a byte at a certain position, i, from x,
	 * with byte b.
	 */

	// Shifts i to the left by three bits.
	int i_times_8 = i << 3;

	// Creates a mask to zero the lowest 8 bits of x, and shifts the mask by the amount that was calculated from the first step (i_times_8).   	
	unsigned int mask = 0xFF << i_times_8;

	// Shifts b by the amount that was calculated from the first step (i_times_8).
	unsigned int shift = b << i_times_8;

	// Uses bitwise AND of the shifted mask and x to zero out the appropriate bits of x.
	// Bitwise OR is used for the shifted b value and x to replace the masked bits from using bitwise AND.
	unsigned int replaced = (x & ~mask) | shift;
	
	// Returns the new 32-bit word that has the replaced byte.
	return replaced;					 
}

int main() {
	/* Prints out the result from calling the replace() function. */
	printf("0x%X\n", replace(0x12345678, 3, 0xAB));
	printf("0x%X\n", replace(0x12345678, 0, 0xAB));
	return 0;
}
