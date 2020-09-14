/* Hans Prieto
 * CIS 314
 * Assignment 2-3
 */
#include <stdio.h>

int ge(float x, float y) {
	unsigned int ux = * ((unsigned int *) &x); // convert x raw bits
	unsigned int uy = * ((unsigned int *) &y); // convert y raw bits
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31;
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	int pos_neg = (sx < sy); // takes into account the case when one number is positive, and another number is negative.
	int both_pos = ((sx == 0) && (sy == 0)) && (ux >= uy); // takes into account the case when both x and y are positive.
	int both_neg = ((sx == 1) && (sy == 1)) && (ux <= uy); // takes into account the case when both x and y are negative.
	int both_zero = ((ux == 0) && (uy == 0)); // takes into account the case when both x and y are zero.
	int result = pos_neg || both_pos || both_neg || both_zero; // determines whether x <= y.
	return result; // returns 1 if x <=y. 0 if not. 
}

int main() {
	/* Prints out the result from calling the ge() function */
	printf("%d\n", ge(0.0f, 0.0f));
	printf("%d\n", ge(-0.0f, 0.0f));
	printf("%d\n", ge(-1.0f, -1.0f));
	printf("%d\n", ge(1.0f, 1.0f));
	printf("%d\n", ge(-1.0f, 0.0f));
	printf("%d\n", ge(0.0f, 1.0f));
	printf("%d\n", ge(1.0f, 0.0f));
	printf("%d\n", ge(0.0f, -1.0f));
	printf("%d\n", ge(-1.0f, -2.0f));
	return 0;
}
