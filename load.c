#include <stdio.h>
#include <stdlib.h>

int *load(char *fileName, int *len)
{
  FILE *f = fopen(fileName, "r");

  fscanf(f, "%d,", len);

  int *v = malloc(sizeof(int) * *len);

  for (int i = 0; i < *len; ++i)
  {
    fscanf(f, "%d,", &v[i]);
  }

  fclose(f);

  return v;
}