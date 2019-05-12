#include "../thirdparty/ctest.h"
#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

int array[10] = {7, 6, 9, 1, 0, 8, 2, 3, 4, 5};
int number = 10;

CTEST(sorts_test, bubble_sort)
{
    int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bubble(array, number);
    int i;

    for (i = 0; i < number; i++)
        ASSERT_EQUAL(expected[i], array[i]);
}

CTEST(sorts_test, quick_sort)
{
    int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    quick(array, 0, number - 1);
    int i;

    for (i = 0; i < number; i++)
        ASSERT_EQUAL(expected[i], array[i]);
}

CTEST(other_test, swap)
{
    int a = 1, b = 5;

    swap(&a, &b);

    ASSERT_EQUAL(a, 5);
    ASSERT_EQUAL(b, 1);
}