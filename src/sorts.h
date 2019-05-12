#ifndef H_SORTS
#define H_SORTS

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void quick(int* array_q, int left, int right);
void bubble(int* array_b, int number);
void swap(int* a, int* b);
double time_sort();
void generator(int* array, int number);

#endif