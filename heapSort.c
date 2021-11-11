
#include <stdio.h>
#include <stdlib.h>

int* load(char *fileName)
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

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(int arr[], int n, int i)
{
  int max = i; //Initialize max as root
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;

  //If left child is greater than root
  if (leftChild < n && arr[leftChild] > arr[max])
    max = leftChild;

  //If right child is greater than max
  if (rightChild < n && arr[rightChild] > arr[max])
    max = rightChild;

  //If max is not root
  if (max != i)
  {
    swap(&arr[i], &arr[max]);
    //heapify the affected sub-tree recursively
    heapify(arr, n, max);
  }
}

//Main function to perform heap sort
void heapSort(int arr[], int n)
{
  //Rearrange array (building heap)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  //Extract elements from heap one by one
  for (int i = n - 1; i >= 0; i--)
  {
    swap(&arr[0], &arr[i]); //Current root moved to the end

    heapify(arr, i, 0); //calling max heapify on the heap reduced
  }
}

//print size of array n using utility function
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Driver code */
int main()
{
  printf("running");
  int len = 100000;
  int *randArray = load("data/100000-avg-0.txt");

  // The array containing values to be sorted
  // int sz = 1000000;
  // int randArray[sz], i;
  // for (i = 0; i < sz; i++)
  //   randArray[i] = rand() % 10000000;

  // // Size of the array
  // int arr_size = sizeof(randArray) / sizeof(randArray[0]);

  heapSort(randArray, len);

  printArray(randArray, len);
}