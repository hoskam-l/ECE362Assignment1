#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



//from https://www.geeksforgeeks.org/c-program-sort-array-names-strings/
// Defining comparator function as per the requirement
static int myCompare(const void* a, const void* b)
{

	// setting up rules for comparison
	return strcmp(*(const char**)a, *(const char**)b);
}

// Function to sort the array
void sort(const char* arr[], int n)
{
	// calling qsort function to sort the array
	// with the help of Comparator
	qsort(arr, n, sizeof(const char*), myCompare);
}

int main(int argc, char* argv[])
{
	// find any elements that match -h or -l
	// and make new array of strings with only elements
	bool showHigh = false;
	bool showLow = false;
	char** elemUsed = malloc(argc * sizeof(char*));
	int elemUsedCnt = 0;
	int i;
	if (argc > 0) {
		for (i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-h") == 0)
			{
				showHigh = true;
			}
			else if (strcmp(argv[i], "-l") == 0)
			{
				showLow = true;
			}
			else {
				elemUsed[elemUsedCnt] = malloc(sizeof(argv[i]));
				strcpy(elemUsed[elemUsedCnt], argv[i]);
				elemUsedCnt++;
			}
		}
	}
	
	printf("\n \n");
	// sort list in alphabetical order
	sort((const char**)elemUsed, elemUsedCnt);
	// exit if there are only modifiers and no elements
	if ((showHigh || showLow) && elemUsedCnt < 1) {
		printf("ERROR: invalid arguments \n");
		printf("Usage: filter [-l] [-h] string string ...\n");
		printf("\n \n");
		return(0);
	}
	// if no arguments
	if (!showHigh && !showLow) {
		for (i = 0; i < elemUsedCnt; i++) {
			printf("%s \n", elemUsed[i]);
		}
	}
	// if only showHigh is present
	if (showHigh && !showLow) {
		printf("HIGH: %s \n", elemUsed[elemUsedCnt - 1]);
	}
	// if only showLow is present
	if (showLow && !showHigh) {
		printf("LOW: %s \n", elemUsed[0]);
	}
	// if showHigh and showLow
	if (showHigh && showLow) {
		printf("LOW: %s \n", elemUsed[0]);
		printf("HIGH: %s \n", elemUsed[elemUsedCnt - 1]);
	}
	
	printf("\n \n");
	return (0);
}
