/* Hans Prieto
 * CIS 314
 * Assignment 4-4
 */

/* Original Transpose function:
 * void transpose(array_t a) {
 * 	for (long i = 0; i < N; ++i) {
 *		for (long j = 0; j < i; ++j) {
 *			long t1 = a[i][j];
 *			long t2 = a[j][i];
 *			a[i][j] = t2;
 *			a[j][i] = t1;
 *		}
 *	}
 * }
 */

/* .L3: // beginning of the inner for loop.
 * 	movq  (%rax), %rcx	// Assigns t1 to a[i][j].
 * 	movq  (%rdx), %rsi	// Assigns t2 to a[j][i].  	
 *	movq  %rsi, (%rax)	// Swaps a[i][j] with the value of t2.
 *	movq  %rcx, (%rdx)	// Swaps a[j][i] with the value of t1.
 *	addq  $8, %rax		// Increments the value of i.
 *	addq  $32, %rdx		// Increments the value of j.
 *	cmpq  $r9, %rax		// Checks if j is less than i.
 *	jne   .L3		// Goes back to the beginning of the inner for loop.
 */

#include <stdio.h>
#define N 4
typedef long array_t[N][N];

void transpose_new(array_t a) {
	/* New transpose function */
	for (long i = 0; i < N; ++i) {
		long *rptr = &a[i][0]; // Points to elements in row i of array a. 
		long *cptr = &a[0][i]; // Points to elements in column i of array a.
		for (long j = 0; j < i; ++j) {
			long t1 = *rptr; 
			long t2 = *cptr;
			a[i][j] = t2; // Changes row to column.
			a[j][i] = t1; // Changes column to row.

			rptr++; // Moves rptr to the next column.
			cptr += N; // Moves cptr to the next row.
		}
	}
}

void printArray(array_t a) {
	/* Prints the array representation of a matrix */
	printf("{");
	for (long i = 0; i < N; i++) {
		printf("{");
		for (long j = 0; j < N; j++) {
			printf("%ld", a[i][j]);
			if(j != N - 1) {
				printf(", ", a[i][j]);
			}
			else if(i != N-1 && j == N - 1) {
			       printf("}, ");	       
			}
			else {
				printf("}");
			}
		}
	}
	printf("}");
	printf("\n");
}

int main() {
	/* Test case for the new transpose function */
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	printf("Array before transpose:\n");
	printArray(a);
	printf("\n");
	transpose_new(a);
	printf("Array after transpose:\n");
	printArray(a);
	return 0;
}
