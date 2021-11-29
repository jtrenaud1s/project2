#include "util.h"
#include <stdlib.h>

void countingSort(int list[], int n, int exp)
{
   int *output = malloc(n * sizeof(10000000));
   int i, count[10] = {0};

   // Store count of each character
   for (i = 0; i < n; i++)
      count[(list[i] / exp) % 10]++;

   // Change count[i] so that count[i] now contains actual
   // position of this character in output array
   for (i = 1; i < 10; i++)
      count[i] += count[i - 1];

   // Build the output array
   for (i = n - 1; i >= 0; i--)
   {
      output[count[(list[i] / exp) % 10] - 1] = list[i];
      count[(list[i] / exp) % 10]--;
   }

   // Copy the output array to arr[], so that arr[] now
   // contains sorted numbers according to current digit
   for (i = 0; i < n; i++)
      list[i] = output[i];

   free(output);
}

void radixSort(int list[], int n)
{
   // Get the max item in the array
   int m = getMax(list, n);

   // Run counting sort off of m
   int exp;
   for (exp = 1; m / exp > 0; exp *= 10)
      countingSort(list, n, exp);
}