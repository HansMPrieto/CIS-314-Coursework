/* Hans Prieto
 * CIS 314
 * Assignment 7-1
 */
#include <stdio.h>

unsigned int getOffset(unsigned int address) {
	/* Returns the byte offset of the address
	 * within its cache block.
	 */
	unsigned int mask = 0x000000FF; // mask of 0x000000FF.
	unsigned int offset = address & mask; // Uses a bitwise 'and' to get the offset bit.
	return offset; // Returns the offset bit.
}

unsigned int getSet(unsigned int address) {
	/* Returns the cache set for the address. */
	int shift = 8; // Right shift of 8.
	unsigned int mask = 0x00000F00; // mask of 0x00000F00
	unsigned int extract = address & mask; // Uses a bitwise 'and' to extract the set bits.
	unsigned int set = extract >> shift; // Shifts the extracted set bits to the right by 8 bits.
	return set; // returns the set bits.
}

unsigned int getTag(unsigned int address) {
	/* Returns the cache tag for the address. */
	int shift = 12; // Right shift of 12.
	unsigned int tag = address >> shift; // Shifts the address to the right by 12 bits to get the tag bits.
	return tag; // Returns the tag bits
}

int main() {
	/* Test cases for getOffset(), getSet(), and getTag() functions. */
	printf("0x12345678: offset: %X - tag: %X - set: %X\n", getOffset(0x12345678), getTag(0x12345678), getSet(0x12345678));
	printf("0x87654321: offset: %X - tag: %X - set: %X\n", getOffset(0x87654321), getTag(0x87654321), getSet(0x87654321));
	return 0;
}
