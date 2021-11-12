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

void run(void (*f)(int[], int), char l[], char type[])
{
  char fileName[100] = "data/";

  strcat(fileName, l);
  strcat(fileName, "-");
  strcat(fileName, type);
  strcat(fileName, ".txt");

  printf("Loading file: %s\n", fileName);

  int len = 0;
  int *randArray = load(fileName, &len);

  clock_t start = clock();
  (*f)(randArray, len);
  clock_t stop = clock();

  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f\n", elapsed);
  free(randArray);
}

/* Driver code */
int main(int argc, char **argv)
{
  if (argc == 4)
  {
    if (strcmp("heap", argv[1]) == 0)
    {
      printf("Starting Heap Sort on %s numbers, %s case scenario\n", argv[2], argv[3]);
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
      printf("Available Algorithms: heap, insertion, merge, quick, radix, selection");
    }
  }
  else
  {
    printf("%d args expected, %d given\n\n", 3, argc - 1);
    printf("Usage: ./sort <algorithm> <length> <case>\n");
    printf("Available Algorithms: heap, insertion, merge, quick, radix, selection");

    return -1;
  }
  return 0;
}