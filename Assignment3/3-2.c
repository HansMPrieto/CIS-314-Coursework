/* Hans Prieto
 * CIS 314
 * Assignment 3-2
 */
#include <stdio.h>

long f(long a, long b, long c) {
	/* This function is equivalent to the 
	 * compiled x86-64 code shown below:
	 * 
	 * addq %rsi, %rdx
	 * imulq %rdx, %rdi
	 * salq $63, %rdx
	 * sarq $63, %rdx
	 * movq %rdi, %rax
	 * xorq %rdx, %rax 
	 */	
	long rdi = a; // Declares a variable rdi, and sets its value to equal the value of a. 
	long rsi = b; // Declares a variable rsi, and sets its value to equal the value of b.
	long rdx = c; // Declares a variable rdx, and sets its value to equal the value of c.
	long rax; // Declares the return value.

	rdx = rdx + rsi; // Adds rdx to rsi. (Equivalent to: addq %rsi, %rdx).
	rdi = rdi * rdx; // Multiplies rdi by rdx. (Equivalent to: imulq %rdx, %rdi).
	rdx = rdx << 63; // Shifts rdx to the left by 63 bits. (Equivalent to: salq $63, %rdx).
	rdx = rdx >> 63; // Shifts rdx to the right by 63 bits. (Equivalent to: sarq $63, %rdx).
	rax = rdi; // Assigns rax to rdi. (Equivalent to: movq %rdi, %rax).
	rax = rax ^ rdx; // Uses 'bitwise logical exclusive or' for rax and rdx, and assigns it to the return value of rax.
	// (Equivalent to: xorq %rdx, %rax).
	
	return rax; // Returns the value from the previous step.
}

int main() {
	/* Test cases for the f() function */
	printf("%ld\n", f(1, 2, 4));
	printf("%ld\n", f(3, 5, 7));
	printf("%ld\n", f(10, 20, 30));
	return 0;
}
