#include "sorts.h"

double time_sort()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec+(double)t.tv_usec*1E-6;
}