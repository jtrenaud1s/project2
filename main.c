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

  printf("Starting HeapSort on %s numbers, %s case\n", l, type);

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
    printf("%s, %s, %s\n", argv[1], argv[2], argv[3]);
    if (strcmp("heapSort", argv[1]) != 0)
      run(heapSort, argv[2], argv[3]);
    else if (strcmp("insertionSort", argv[1]) != 0)
      run(insertionSort, argv[2], argv[3]);
    else if (strcmp("mergeSort", argv[1]) != 0)
      run(mergeSort, argv[2], argv[3]);
    else if (strcmp("quickSort", argv[1]) != 0)
      run(quickSort, argv[2], argv[3]);
    else if (strcmp("radixSort", argv[1]) != 0)
      run(radixSort, argv[2], argv[3]);
    else if (strcmp("selectionSort", argv[1]) != 0)
      run(selectionSort, argv[2], argv[3]);
    else
    {
      printf("Available Algorithms: heapSort, insertionSort, mergeSort, quickSort, radixSort, selectionSort");
    }
  }
  else
  {
    printf("%d args expected, %d given\n\n", 3, argc - 1);
    printf("Usage: ./sort <algorithm> <length> <case>\n");
    printf("Available Algorithms: heapSort, insertionSort, mergeSort, quickSort, radixSort, selectionSort\n\n");

    return -1;
  }
  return 0;
}