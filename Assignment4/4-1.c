/* Hans Prieto
 * CIS 314
 * Assignment 4-1
 */

#include <stdio.h>

long loop(long x, long y) {
	/* loop:
	 * 	movq  %rsi, %rcx 	// get y
	 * 	movl  $2, %eax 		// set mask equal to 2
	 * 	movq  $-1, %rdx 	// set result equal to -1
	 * .L2:
	 * 	cmpq  $1, %rax 		// check if mask is greater than 1
	 * 	jle   .L4 		// if mask is less than 1, go to L4 and return result
	 * 	movq  %rax, %r8 	// gets mask
	 * 	andq  %rdi, %r8 	// uses bitwise logical "and" between x and the mask	
	 * 	xorq  %r8, %rdx		// uses bitwise logical exclusive "OR" between the result to be returned and the outcome from (x & mask)
	 * 	salq  %cl, %rax		// shift mask to the left by y bits
	 * 	jmp   .L2		// continues for loop if mask is greater than 1
	 * .L4:
	 * 	movq  %rdx, %rax	// gets the result to be returned
	 * 	ret			// returns the result
	 */

	long result = -1;
	for (long mask = 2; mask > 1; mask <<= y) {
		result ^= (x & mask);
	}
	return result;
}

int main() {
	/* test cases for loop() function */
	printf("%ld\n", loop(1, 5));
	printf("%ld\n", loop(2, 4));
	printf("%ld\n", loop(3, 3));
	printf("%ld\n", loop(4, 2));
	printf("%ld\n", loop(5, 1));
	return 0;
}
