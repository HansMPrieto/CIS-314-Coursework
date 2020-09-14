/* Hans Prieto
 * CIS 314
 * Assignment 8-1
 */
#include <stdio.h>
#include <stdlib.h>

struct Line {
	unsigned char data[4];
	unsigned int tag;
	unsigned char valid;
};

struct Cache {
	struct Line *lines;
	int numLines;
};

unsigned int getOffset(unsigned int address) {
	// 4B blocks, so offset is bits 0-1
	return address & 0x3;
}

unsigned int getSet(unsigned int address) {
	// 16 sets, so offset is bits 2-6
	return (address >> 2) & 0xF;
}

unsigned int getTag(unsigned int address) {
	// Offset and set are 6 bits total, so tag is high-order 26 bits
	return address >> 6;
}

struct Cache* mallocCache(int numLines) {
	// Mallocs a pointer to a struct Cache, malloc a pointer to an array
	// of struct Line instances (array length is numLines). Also initialize
	// valid to 0 for each struct Line. Return the struct Cache pointer.
	struct Cache * cacheptr = (struct Cache*) malloc(sizeof(struct Cache));
	cacheptr->numLines = numLines;
	cacheptr->lines = (struct Line*) malloc(sizeof(int) * numLines);
	return cacheptr;
}

void freeCache(struct Cache *cache) {
	free(cache->lines);
	free(cache);
}

void printCache(struct Cache *cache) {
	// Prints all valid lines in the cache.
	for (int i = 0; i < 4; ++i) {
		struct Line *line = &cache->lines[i];
		if (line->valid) {
			unsigned char *data = line->data;
			printf("set: %x - tag: %x - valid: %u - data: %.2x %.2x %.2x %.2x\n",
			i, line->tag, line->valid, data[0], data[1], data[2], data[3]);
		}
	}
}

void readValue(struct Cache *cache, unsigned int address) {
	// Checks the cache for a cached byte at the specified address.
	// If found, indicate a hit and print the byte. If not found, indicate
	// a miss due to either an invalid line (cold miss) or a tag mismatch
	// (conflict miss).
	
	// Calculate offset, set, and tag for address
	unsigned int o = getOffset(address);
	unsigned int s = getSet(address);
	unsigned int t = getTag(address);

	// Get pointer to cache line in the specified set
	struct Line *line = &cache->lines[s];
	
	printf("looking for set: %x - tag: %x\n", s, t);

	// Checks if the chache for a cached byte at the specified address
	// is found.
	if (line->valid) {
		unsigned char *data = line->data;
		printf("found set: %x - tag: %x - offset: %x - valid: %u - data: %.2x\n",
			s, line->tag, o, line->valid, data[o]);
		if (line->tag == t){
			printf("hit!\n"); // Indicates a hit if the cache is found.
		}
		else {
			printf("tags don't match - miss!\n"); // Indicates a miss if there is a tag mismatch (conflict miss).
		}
	}

	else {
		printf("no valid line found - miss!\n"); // Indicates a miss if there is an invalid line.
	}
}

void writeValue(struct Cache *cache, unsigned int address, unsigned char *newData) {
	// Calculate set and tag for address
	unsigned int s = getSet(address);
	unsigned int t = getTag(address);

	// Get pointer to cache line in the specified set
	struct Line *line = &cache->lines[s];

	// Determine if we have a valid line in the cache that does not contain the
	// specified address - we detect this by checking for a tag mismatch
	if (line->valid && line->tag != t) {
		unsigned char *data = line->data;
		printf("evicting line - set: %x - tag: %x - valid: %u - data: %.2x %.2x %.2x %.2x\n",
			s, line->tag, line->valid, data[0], data[1], data[2], data[3]);
	}

	// Copy new data to line (could use memcpy here instead)
	for (int i = 0; i < 4; ++i) {
		line->data[i] = newData[i];
	}

	// Update line tag, mark line as valid
	line->tag = t;
	line->valid = 1;

	printf("wrote set: %x - tag: %x - valid: %u - data: %.2x %.2x %.2x %.2x\n",
		s, line->tag, line->valid, newData[0], newData[1], newData[2], newData[3]);
}

int main() {
	struct Cache *cache = mallocCache(16);
	
	// Loop until user enters 'q'
	char c;
	do {
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		scanf(" %c", &c);

		if (c == 'r') {
			printf("Enter 32-bit unsigned hex address: ");
			
			unsigned int a;
			scanf(" %x", &a);
		
			readValue(cache, a);
		} else if (c == 'w') {
			printf("Enter 32-bit unsigned hex address: ");

			unsigned int a;
			scanf(" %x", &a);

			printf("Enter 32-bit unsigned hex value: ");
		
			unsigned int v;
			scanf(" %x", &v);
		
			// Get byte pointer to v
			unsigned char *data = (unsigned char *)&v;
			
			writeValue(cache, a, data);
		} else if (c == 'p') {
			printCache(cache);
		}
	} while (c != 'q');

	freeCache(cache);
}
