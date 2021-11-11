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

void insertionSort(int array[], int size)
{
  for (int step = 1; step < size; step++)
  {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/* Driver code */
int main()
{
  int len = 100000;
  int *randArray = load("data/100000-avg-0.txt");
  // The array containing values to be sorted
  // int sz = 10000000;
  // int randArray[sz], i;
  // for (i = 0; i < sz; i++)
  //   randArray[i] = rand() % 10000000;

  // // Size of the array
  // int arr_size = sizeof(randArray) / sizeof(randArray[0]);

  insertionSort(randArray, len);

  printArray(randArray, len);
}
