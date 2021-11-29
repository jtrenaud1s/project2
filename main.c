#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "heapSort.h"
#include "load.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"

// Run a function (algorithm) given the length of the array to run and the sorting order to load
void run(void (*f)(int[], int), char l[], char type[])
{
  // all data files are in data/
  char fileName[100] = "data/";

  // concatenate the length and sorting order to the filename with extension
  strcat(fileName, l);
  strcat(fileName, "-");
  strcat(fileName, type);
  strcat(fileName, ".txt");

  printf("Loading file: %s\n", fileName);

  // Load the array from the file
  int len = 0;
  int *randArray = load(fileName, &len);

  // Run the selected algorithm with a timer
  clock_t start = clock();
  (*f)(randArray, len);
  clock_t stop = clock();

  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);
  
  // free the memory used by the array
  free(randArray);
}

/* Driver code */
int main(int argc, char **argv)
{

  // If 3 arguments were provided (command included first)
  if (argc == 4)
  {
    // Second argument is the algorithm to run
    if (strcmp("heap", argv[1]) == 0)
    {
      printf("Starting Heap Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      // third and fourth are array length and sorting order
      run(heapSort, argv[2], argv[3]);
    }
    else if (strcmp("insertion", argv[1]) == 0)
    {
      printf("Starting Insertion Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      run(insertionSort, argv[2], argv[3]);
    }
    else if (strcmp("merge", argv[1]) == 0)
    {
      printf("Starting Merge Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      run(mergeSort, argv[2], argv[3]);
    }
    else if (strcmp("quick", argv[1]) == 0)
    {
      printf("Starting Quick Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      run(quickSort, argv[2], argv[3]);
    }
    else if (strcmp("radix", argv[1]) == 0)
    {
      printf("Starting Radix Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      run(radixSort, argv[2], argv[3]);
    }
    else if (strcmp("selection", argv[1]) == 0)
    {
      printf("Starting Selection Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
      run(selectionSort, argv[2], argv[3]);
    }
    else
    {
      // Invalid algorithm selection or none made
      printf("Available Algorithms: heap, insertion, merge, quick, radix, selection");
    }
  }
  else
  {
    // How to use the program
    printf("%d args expected, %d given\n\n", 3, argc - 1);
    printf("Usage: ./sort <algorithm> <length> <case>\n");
    printf("Available Algorithms: heap, insertion, merge, quick, radix, selection");

    return -1;
  }
  return 0;
}