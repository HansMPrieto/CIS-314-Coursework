/* Hans Prieto
 * CIS 314
 * Assignment 4-3
 */

#include <stdio.h>

long fact(long x) {
	/* Implements factorial method */
	if (x <= 1) {
		return 1;
	}

	long px = x; // Uses a push operation to save the current value of x as long as x is greater than 1.
	long fx = fact(x - 1); // Uses a pop operation from making the recursive call to fact, and pops all of the x values on the stack greater than 1.
	return px * fx; // Uses a pop operation to multiply each of the x values together that were on the stack that are greater than 1, and make a return call to get the result.
}

int main() {
	/* Test cases for the fact() function */
	printf("%ld\n", fact(1));
	printf("%ld\n", fact(2));
	printf("%ld\n", fact(3));
	printf("%ld\n", fact(4));
	printf("%ld\n", fact(5));
	printf("%ld\n", fact(6));
	return 0;
}
