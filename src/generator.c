#include "sorts.h"

void generator(int* array, int number)
{
    int i, j;
    int min = 0, max = 1000;

    srand(time(NULL));

    for (i = 0; i < number; i++) {
		j = min + rand() % (max - min + 1);
        array[i] = j;
	}
}