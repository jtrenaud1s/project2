#include <stdio.h>

//print size of array n using utility function
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}