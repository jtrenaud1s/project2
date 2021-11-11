#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++)
  {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    swap(&arr[min_idx], &arr[i]);
  }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Driver code */
int main()
{

  // The array containing values to be sorted
  int sz = 10000;
  int randArray[sz], i;
  for (i = 0; i < sz; i++)
    randArray[i] = rand() % 10000;

  // Size of the array
  int arr_size = sizeof(randArray) / sizeof(randArray[0]);

  selectionSort(randArray, arr_size);

  printArray(randArray, arr_size);

  // Function call for the Radix Sort Algorithm
}