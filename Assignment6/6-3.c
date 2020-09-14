/* Hans Prieto
 * CIS 314
 * Assignment 6-3
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n) {
	/* Computers the product of nonzero elements in an array */
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float g(float *a, int n) {
	/* Function that has a similar functionality as f,
	 * but without the zero (i.e., if a[i] != 0.0f) check.
	 *
	 * Computes the product of each element in an array.
	 */
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		prod *= a[i];
	}
	return prod;
}

float* createArray(int size) {
	/* Creates an array of a certain size */
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		// [0.76, 1.26] otherwise.
		float r = rand()/(float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}

int main(){
	clock_t start;
	clock_t end;
	double total_time;
	int i;
	int j;
	int size = 10000;
	
	// Part a:
	// Creates an array a using createArray(10000), and then
	// measures the time it takes to run f(a).
	float *a = createArray(size);
	float *original_a = a;
	start = clock(); // start clock
	f(a, size);
	end = clock(); // end clock
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Product of calling f(a): %f\n", f(a, size));
	printf("Time to call f(a): %f seconds.\n", total_time);
	printf("\n");

	// Creates a new array b, containing the same elements as a but
	// with every 0.0f replaced by 1.0f
	float *b = a;
	for (i = 0; i < size; ++i) {
		if (b[i] == 0.0f) {
			b[i] = 1.0f;
		}
	}
	
	// Part b:
	// Measures the time it takes to run g(b).
	//
	// The time it takes to run g(b) is faster than calling
	// f(a) because g(b) doesn't have to check whether an element
	// in an array equals 0.0f, whereas f(a) has to check this condition.
	start = clock(); // start clock
	g(b, size);
	end = clock(); // end clock
	total_time = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("Product of calling g(b): %f\n", g(b, size));
	printf("Time to call g(b): %f seconds.\n", total_time);
	printf("\n");

	// Creates a new array c, containing only the nonzero
	// elements from array a.
	float *c = original_a;
	for (i = 0; i < size; ++i) {
		if (c[i] == 0) {
			for(j = i; j < size; ++j) {
				c[j] = c[j+1];
			}
			size--;
			i--;
		}
	}

	// Part c:
	// Measures the time it takes to run g(c).
	//
	// The time it takes to run g(c) is sometimes faster than calling f(a) and g(b)
	// because when calling g(c), the array c has fewer elements than array
	// a or array b. The less elements there are in an array, the less time
	// it takes for the function to execute. 
	int new_size = size;
	start = clock(); //start clock
	g(c, new_size);
	end = clock(); // end clock
	total_time = ((double) (end-start)) / CLOCKS_PER_SEC;
	printf("Product of calling g(c): %f\n", g(c,size));
	printf("Time to call g(c): %f seconds.\n", total_time);	

	free(c);
}

