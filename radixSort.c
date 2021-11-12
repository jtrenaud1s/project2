#include "util.h"
#include <stdlib.h>

void countingSort(int list[], int n, int exp)
{
   int *output = malloc(n * sizeof(10000000));
   int i, count[10] = {0};

   for (i = 0; i < n; i++)
      count[(list[i] / exp) % 10]++;

   for (i = 1; i < 10; i++)
      count[i] += count[i - 1];

   for (i = n - 1; i >= 0; i--)
   {
      output[count[(list[i] / exp) % 10] - 1] = list[i];
      count[(list[i] / exp) % 10]--;
   }

   for (i = 0; i < n; i++)
      list[i] = output[i];

   free(output);
}

void radixSort(int list[], int n)
{
   int m = getMax(list, n);

   int exp;
   for (exp = 1; m / exp > 0; exp *= 10)
      countingSort(list, n, exp);
}