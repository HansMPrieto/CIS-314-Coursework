/* Hans Prieto
 * CIS 314
 * Assignment 4-2 
 */

/* Original Function:
 * long sum(long n) {
 *	if (n < 1) {
 *		return 0;
 *	}
 *
 *	long i = 1;
 *	long result = 0;
 *	do {
 *		result += i;
 *		++i;
 *	} while (i <= n);
 *	return result;
 * }
 */

/* Sum Function that replaces the loop with a 
 * goto statement and label:
 * long goto_sum(long n) {
 *	if (n < 1) {
 *		return 0;
 *	}
 *
 *	long i = 1;
 *	long result = 0;
 *	loop:
 *		result += i;
 *		++i;
 *	if (i <= n)
 *		goto loop;
 *	return result;	
 * }
 */

#include <stdio.h>

long new_sum(long n) {
	/* Implements the goto_sum() function by using
	 * x86-64 code.
	 */
	if (n < 1) {
		return 0;
	}

	long i = 1;
	long result = 0;
	// Ensure that argument *n* is in %rdi, *i* is in %rcx,
	// *result* is in %rax - do not modify.
	__asm__ ("movq %0, %%rdi # n in rdi;" :: "r" ( n ));
	__asm__ ("movq %0, %%rcx # i in rcx;" :: "r" ( i ));
	__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));

	__asm__(".loop:" // Beginning of loop.
		"addq %rcx, %rax;" // Adds the result by the current value of i.
		"addq $1, %rcx;" // Increments the value of i.
	      	"cmpq %rdi, %rcx;" // Checks if i is less than or equal to n.
		"jle .loop;" // If i is less than or equal to n, go back to the beginning of the loop.
		"movq %rax, %rbx;" // Saves the return result.
		"movq %rbx, %rax;" // Gets the return result. 
	);
	
	// Ensure that *result* is in rax for return - do not modify.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;
}

int main() {
	/* Test cases for new_sum() function */
	printf("%ld\n", new_sum(1));
	printf("%ld\n", new_sum(3));
	printf("%ld\n", new_sum(5));
	printf("%ld\n", new_sum(7));
	return 0;
}
