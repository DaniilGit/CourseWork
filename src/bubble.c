#include "sorts.h"

void bubble(int *array_b, int number)
{
  int i, j;
  
  for (i = number - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
        if (array_b[j] > array_b[j + 1])
            swap(&array_b[j], &array_b[j + 1]);
    }
  }
}

void swap(int* a, int* b)
{
    int buffer;

    buffer = *a;
    *a = *b;
    *b = buffer;
}
