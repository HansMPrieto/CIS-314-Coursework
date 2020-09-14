/* Hans Prieto
 * CIS 314
 * Assignment 7-2c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}

struct ColorPoint** create2DArray(int n) {
	// Array to hold a pointer to the beginning of each row
	struct ColorPoint **points = (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i) {
		// Array to hold each row
		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
		for (int j = 0; j < n; ++j) {
			// Init the ColorPoint struct
			points[i][j].a = rand();
			points[i][j].r = rand();
			points[i][j].g = rand();
			points[i][j].b = rand();
		}
	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n) {
	for (int i = 0; i < n; ++i) {
		free(points[i]);
	}
	free(points);
}

int main() {
	/* After timing the f() and g() functions, it was shown that
	 * the g() function executes faster than the f() function.
	 * This might be the case because in the g() function, the
	 * rows are being summed, while in the f() function, the
	 * cols are being summed. 
	 *
	 * The sum for the g() function is computed as sum += points[i][j]
	 *
	 * On the other hand, the sum for the f() function is computed
	 * as sum += points[j][i]
	 *
	 * The g() function seems to have better locality with respect
	 * to the 2D array, rather than the f() function, and therefore,
	 * the g() function executes faster than the f() function. 
	 */
	clock_t start;
	clock_t end;
	double total_time;
	int size = 2048;

	struct ColorPoint** points = create2DArray(size);

	// Timing of f() function.
	start = clock();
	f(points, size);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time to call f() function: %f seconds.\n", total_time);

	// Timing of g() function.
	start = clock();
	g(points, size);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time to call g() function: %f seconds.\n", total_time);
	
	// Frees the memory used for the array.
	free2DArray(points, size);

	return 0;
}
