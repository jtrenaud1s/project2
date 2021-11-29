#include <stdio.h>
#include <stdlib.h>

int *load(char *fileName, int *len)
{
  // Create a pointer to a file
  FILE *f = fopen(fileName, "r");
  // Read the first integer in the file, which is the length of the array
  fscanf(f, "%d,", len);

  // Allocate memory for the array, int size * array size
  int *v = malloc(sizeof(int) * *len);

  // Keep reading integers seperated by commas until we've reached len
  for (int i = 0; i < *len; ++i)
  {
    fscanf(f, "%d,", &v[i]);
  }

  // Close the file for memory leaks
  fclose(f);

  return v;
}