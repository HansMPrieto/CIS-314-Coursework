/* Hans Prieto
 * CIS 314
 * Assignment 6-2c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100000 // change this to change the input size

typedef float array_t[N];

// Original inner function.
void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {
		sum += u[i] * v[i];
	}
	*dest = sum;
	printf("Result of inner: %.6f\n", *dest);
}

// New inner function that uses loop unrolling.
void inner2(float *u, float *v, int length, float *dest) {
	int i;
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	float sum4 = 0.0f;

	/* Combine 4 elements at a time */
	for (i = 0; i < length; i+=4){
		sum1 += u[i] * v[i];
		sum2 += u[i+1] * v[i+1];
		sum3 += u[i+2] * v[i+2];
		sum4 += u[i+3] * v[i+3];
	}

	/* Finish any remaining elements */
	for (; i < length; i++){
		sum1 += u[i] * v[i];
	}
	*dest = sum1 + sum2 + sum3 + sum4;
	printf("Result of inner2: %.6f\n", *dest);
}

int main() {
	clock_t start; //example code from class to track time
	clock_t end;
	double total_time;
	
	srand(0); //random seed for inner arguments
	
	float x = (float)rand()/(float)(RAND_MAX/1.45);
	array_t u;
	array_t v;
	float z;
	
	for(int i = 0; i < N; i++) {
		u[i] = x;
		v[i] = x * 1.1;
	}
	printf("Array length: %d\n", N);
	printf("\n");

	start = clock(); // start clock for the first inner() function
	
	inner(u, v, N, &z); // function call with randomish values
	
	end = clock(); // end clock for the first inner() function
	
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Time for inner() function: %f seconds.\n", total_time);
	printf("\n");

	start = clock(); // start clock for inner2() function

	inner2(u, v, N, &z); // function call with randomish values

	end = clock(); // end clock for inner2() function

	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Time for inner2() function: %f seconds.\n", total_time);

	return 0;
}
