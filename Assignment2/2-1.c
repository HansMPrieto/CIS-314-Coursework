/*Hans Prieto
 * CIS 314
 * Assignment 2-1
 */
#include <stdio.h>

int mask(int n) {
	/* Returns a bit mask containing 1s for
	 * the least significant n bits.
	 */

	// Takes a 1, and shifts it left by n bits.
	int shifted_bits = 1 << n;

	// Takes the result above, and subtracts it by 1,
	// getting the masked number with the least 
	// significant n digits set to 1.
	int masked_number = shifted_bits - 1;

	// Returns the masked number with the least
	// significant n digits set to 1.
	return masked_number;
}

int main() {
	/* Prints out the result from calling the mask() function. */
	printf("0x%X\n", mask(1));
	printf("0x%X\n", mask(2));
	printf("0x%X\n", mask(3));
	printf("0x%X\n", mask(5));
	printf("0x%X\n", mask(8));
	printf("0x%X\n", mask(16));
	printf("0x%X\n", mask(31));
	return 0;
}
