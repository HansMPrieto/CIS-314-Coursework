/* Hans Prieto 
 * CIS 314
 * Assignment 3-1
 */

/* Sources used:
 *
 * Bubble Sort Algorithm:
 * https://www.geeksforgeeks.org/bubble-sort/
 *
 * Example of using fgets:
 * https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
 * 
 * Example of using strtol:
 * https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bufsize 2048

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray *mallocIntArray(int length) {
	/* Allocates, initializes, and returns a pointer
	 * to a new struct intArray.
	 */
	struct IntArray * st = (struct IntArray*) malloc(sizeof(struct IntArray)); // Malloc call for the instance.
	st->length = length; // Initializes the length.
	st->dataPtr = (int *) malloc(sizeof(int) * length);  // Malloc call for the instance's dataPtr.
	return st; // Returns the instance.
}

void freeIntArray(struct IntArray *arrayPtr) {
	/* Frees the instance's dataPtr, and 
	 * Frees the instance.
	 */
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array) {
	/* Prompts and reads positive (>0) ints from 
	 * the user to fill the array.
	 */
	int i = 0;
	int input_length;
	int n = array->length;
	char input[bufsize];
	char *ptr;
	int element;

	while(i < n) {
	       printf("Enter int: "); //Prompts the user to enter a positive int.
	       fgets(input, bufsize, stdin);
	       input_length = strlen(input);
	       element = strtol(input, &ptr, 10);
	       if (element <= 0) { // If the element is <= 0, then it prints an error message.
		       printf("Invalid input\n");
	       }
	       else { // If the element is positive, add it to the array.
		       array->dataPtr[i] = element;
		       i++;
	       }
	}	       
}


void swap(int *xp, int *yp) {
	/* Swaps the int values stored at
	 * the xp and yp pointers.
	 */
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sortIntArray(struct IntArray *array) {
	/* Sorts the input array in ascending order using
	 * Bubble Sort.
	 * 
	 * Wrote the Bubble Sort Algorithm based on the one
	 * used in GeeksForGeeks:
	 *
	 * https://www.geeksforgeeks.org/bubble-sort/
	 */
	int i;
	int j;
	int n = array->length;

	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-i-1; j++) {
			if (array->dataPtr[j] > array->dataPtr[j+1]) {
				swap(&array->dataPtr[j], &array->dataPtr[j+1]);
			}
		}
	}
}

void printArray(struct IntArray *array) {
	/* Prints the array with elements in ascending order.
	 * (e.g., "[ 1, 3, 5, 7 ]")
	 */
	int i;
	int size = array->length;
	printf("[ ");
	for (i = 0; i < size; i++) {
		printf("%d", array->dataPtr[i]);
		if (i != size-1) {
			printf(", ");
		}
		else {
			printf(" ]");
		}
	}
	printf("\n");
}

int main() {
	/* Prompts the user to input a positive (>0)
	 * int length from the user to fill the array 
	 * (i.e., read one int for each array index).
	 *
	 * (Prints an error message and prompt again 
	 * if the input cannot be parsed as a positive int.)
	 *
	 * Calls mallocIntArray to create an array.
	 *
	 * Calls readIntArray to prompt the user to fill the array.
	 *
	 * Calls sortIntArray to sort it.
	 *
	 * Calls printArray to print the resulting sorted array.
	 *
	 * Calls freeIntArray to free the heap memory used by the array.
	 */
	char input[bufsize];
	int length;
	char *ptr;
	
	printf("Enter length: ");
	fgets(input, bufsize, stdin); 
	length = strtol(input, &ptr, 10);
	while(length <= 0) {
		printf("Invalid input\n");
		printf("Enter length: ");
		fgets(input, bufsize, stdin);
		length = strtol(input, &ptr, 10);
	}
	struct IntArray *array = mallocIntArray(length);
	readIntArray(array);
	sortIntArray(array);
	printArray(array);
	freeIntArray(array);
	return 0;
}
