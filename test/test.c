#include "../thirdparty/ctest.h"
#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

#define number 1024

CTEST(sorts_test, bubble_sort)
{
    int* array = NULL;
    int expected = 1024;

    array = (int*)malloc(number * sizeof(int));
    generator(array, number);

    bubble(array, number);
    int i, real = 0;

    for (i = 0; i < number; i++) {
        if (array[i] <= array[i + 1])
            real++;
        else
            real--;
    }

    ASSERT_EQUAL(expected, real);
}

CTEST(sorts_test, quick_sort)
{
    int* array = NULL;
    int expected = 1024;

    array = (int*)malloc(number * sizeof(int));
    generator(array, number);

    quick(array, 0, number - 1);
    int i, real = 0;

    for (i = 0; i < number; i++) {
        if (array[i] <= array[i + 1])
            real++;
        else
            real--;
    }

    ASSERT_EQUAL(expected, real);
        
}

CTEST(other_test, swap)
{
    int a = 1, b = 5;

    swap(&a, &b);

    ASSERT_EQUAL(a, 5);
    ASSERT_EQUAL(b, 1);
}