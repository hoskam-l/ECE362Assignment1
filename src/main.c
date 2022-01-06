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
	//int n = sizeof(**argv) / sizeof(*argv[0]);

	//int order[500];
	bool showHigh = false;
	bool showLow = false;
	if (argc > 1) {
		//int high = 5000;
		//int low = 5000;

		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-h") == 0)
			{
				showHigh = true;
			}
			else if (strcmp(argv[i], "-l") == 0)
			{
				showLow = true;
			}
		}
	}
	sort((const char**)argv, argc);
	if (!showHigh && !showLow) {
		for (int i = 0; i < argc; i++) {
			if (!strcmp(argv[i], "-h") == 0 || !strcmp(argv[i], "-l") == 0)
				printf("%s \n", argv[i]);
		}
	}
	if (showHigh && !showLow) {
		printf("HIGH: %s \n", argv[argc-1]);
	}
	if (showLow && !showHigh) {
		int i = 0;
		bool isWord = false;
		while (!isWord) {
			if (strcmp(argv[i], "-h") == 0) i++;
			else if (strcmp(argv[i], "-l") == 0) i++;
		
			else {
				isWord = true;
			}
		}
		printf("LOW: %s \n", argv[i+1]);
	}
	if (showHigh && showLow) {
		int i = 0;
		bool isWord = false;
		while (!isWord) {
			if (strcmp(argv[i], "-h") == 0) i++;
			else if (strcmp(argv[i], "-l") == 0) i++;
		
			else {
				isWord = true;
			}
		}
		printf("LOW: %s \n", argv[i+1]);
		printf("HIGH: %s", argv[argc-1]);
	}

	return (0);
}