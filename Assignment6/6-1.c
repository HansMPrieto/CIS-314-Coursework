/* Hans Prieto
 * CIS 314
 * Assignment 6-1
 */
#include <stdio.h>

// Implementation of the procuedure f that removes
// all multiplications from inside the loop. 
int f(int a, int b, int c, int d, int n) {
	int result = 0;
	int icd = 0;
	int ab = a * b; // Multiplies a by b
	int cd = c * d; // Multiplies c by d
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result += ab + icd + j; // adds the result to be returned with ab, icd, and j
		}
		icd += cd; // adds icd to the product of cd
	}
	return result; // returns the result
}

int main() {
	/* Test cases for the f() function */
	printf("%d\n", f(1, 2, 3, 4, 5));
	printf("%d\n", f(2, 3, 4, 5, 6));
	printf("%d\n", f(6, 5, 4, 3, 2));
	printf("%d\n", f(5, 4, 3, 2, 1));
	return 0;
}
