#include "sorts.h"

void quick(int* array_q, int left, int right) {
	int position;
	int left_copy = left;
	int right_copy = right;

	position = array_q[right];

	while (left < right) {
		while (array_q[left] < position)
			left++;
		while (array_q[right] > position)
			right--;
		if (left < right) {
            swap(&array_q[right], &array_q[left]);
			left++;
			right--;
		}	
	}
	array_q[right] = position;
	position = right;
	right = right_copy;
	left = left_copy;

	if (left < position)
		quick(array_q, left, position - 1 );
	if (right > position)
		quick(array_q, position + 1, right);
}