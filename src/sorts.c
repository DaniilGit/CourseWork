#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"
#include "time.h"

int main()
{
    int number;

    for (number = 256; number <= 32768; number = number + 2048) {

        int i;
        int *array_q = NULL;
        int *array_b = NULL;

        array_q = (int*)malloc(number * sizeof(int));
        array_b = (int*)malloc(number * sizeof(int));

        generator(array_q, number);
        generator(array_b, number);

        double t = time_sort();
        bubble(array_b, number);
        t = time_sort() - t;
        double t_b = t;

        t = time_sort();
        quick(array_q, 0, number - 1);
        t = time_sort() - t;
        double t_q = t;

        for (i = 0; i < number - 1; i++) {
            if (array_b[i] > array_b[i + 1]) {
                printf("The array_bubble is not sorted");
                return -1; 
            }
            if (array_q[i] > array_q[i + 1]) {
                printf("The array_quick is not sorted");
                return -1; 
            }
        }

        printf("\n");
        printf("%d\t", number);
        printf("Time Bubble Sort = %.10f\n\t", t_b);
        printf("Time Quick Sort = %.10f\n", t_q);

        free(array_b);
        free(array_q);
    }

    return 0;
}