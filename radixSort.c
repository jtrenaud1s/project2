
#include <stdio.h>
#include <stdlib.h>

int *load(char *fileName)
{

   FILE *f = fopen(fileName, "r");
   int n;
   fscanf(f, "%d,", &n);
   int *v = malloc(sizeof(int) * n);
   for (int i = 0; i < n; ++i)
   {
      fscanf(f, "%d,", &v[i]);
   }
   fclose(f);

   return v;
}

// Print an array
void printArray(int array[], int size)
{
   for (int i = 0; i < size; ++i)
   {
      printf("%d  ", array[i]);
   }
   printf("\n");
}

int getMax(int array[], int n)
{
   int max = array[0];
   for (int i = 1; i < n; i++)
      if (array[i] > max)
         max = array[i];
   return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place)
{
   int output[size + 1];
   int max = (array[0] / place) % 10;

   for (int i = 1; i < size; i++)
   {
      if (((array[i] / place) % 10) > max)
         max = array[i];
   }
   int count[max + 1];

   for (int i = 0; i < max; ++i)
      count[i] = 0;

   // Calculate count of elements
   for (int i = 0; i < size; i++)
      count[(array[i] / place) % 10]++;

   // Calculate cumulative count
   for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];

   // Place the elements in sorted order
   for (int i = size - 1; i >= 0; i--)
   {
      output[count[(array[i] / place) % 10] - 1] = array[i];
      count[(array[i] / place) % 10]--;
   }

   for (int i = 0; i < size; i++)
      array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size)
{
   // Get maximum element
   int max = getMax(array, size);

   // Apply counting sort to sort elements based on place value.
   for (int place = 1; max / place > 0; place *= 10)
      countingSort(array, size, place);

   printArray(array, size);
}

int main()
{
   int len = 100000;
   int *randArray = load("data/100000-avg-0.txt");
   // The array containing values to be sorted
   // unsigned int sz = 1000000;
   // unsigned int randArray[sz], i;
   // for (i = 0; i < sz; i++)
   //    randArray[i] = rand() % 10000000;

   // // Size of the array
    int n = sizeof(randArray) / sizeof(n);

   // Function call for the Radix Sort Algorithm
   printf("test");
   radixsort(randArray, len);
   return 1;
}
